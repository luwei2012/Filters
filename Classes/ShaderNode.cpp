//
//  ShaderNode.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-13.
//
//

#include "ShaderNode.h"


bool ShaderNode::initWithVertex(const char* vert, const char* frag){
    loadShaderVertex(vert, frag);
    m_texture = Director::getInstance()->getTextureCache()->addImage("HelloWorld.png")->getName();
    Size winsize = Director::getInstance()->getWinSize();
    setContentSize(winsize);
    setColor(Color4F(0.5, 0.5, 0.0, 1.0));
    m_time = 0.0;
    scheduleUpdate();
    return true;
}

void ShaderNode::loadShaderVertex(const char* vert , const char* frag){
    GLProgram* shader = new GLProgram();
    shader->initWithFilenames(vert, frag);//载入着色器程序
    
    //绑定attribute变量
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    shader->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    shader->link();
    
    //获取attribute变量标志
    m_attributeColor = glGetAttribLocation(shader->getProgram(), GLProgram::ATTRIBUTE_NAME_COLOR);
    m_attributePosition = glGetAttribLocation(shader->getProgram(), GLProgram::ATTRIBUTE_NAME_POSITION);
    shader->updateUniforms();
    
    //获取uniform变量
    m_uniformResolution = glGetUniformLocation(shader->getProgram(), "resolution");
    m_uniformTex0 = glGetUniformLocation(shader->getProgram(), "tex0");
    m_uniformTime = glGetUniformLocation(shader->getProgram(), "time");
    
    //使用着色器程序
    this->setGLProgram(shader);
    shader->release();
    
}

void ShaderNode::update(float dt){
    m_time += dt;
}

void ShaderNode::setContentSize(const Size& var){
    Node::setContentSize(var);
    m_resolution = Vec2(getContentSize().width,getContentSize().height);
    m_center.x = m_resolution.x/2;
    m_center.y = m_resolution.y/2;
}

void ShaderNode::setColor(Color4F newColor){
    color[0] = newColor.r;
    color[1] = newColor.g;
    color[2] = newColor.b;
    color[3] = newColor.a;
}

void ShaderNode::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags){
    m_customCommand.init(_globalZOrder);
    m_customCommand.func = CC_CALLBACK_0(ShaderNode::drawWaves, this);
    renderer->addCommand(&m_customCommand);
}

void ShaderNode::drawWaves(){
    CC_NODE_DRAW_SETUP();
    GLProgram* shader = getGLProgram();
    
    //传递变量
    shader->setUniformLocationWith2f(m_uniformResolution, m_resolution.x, m_resolution.y);
    shader->setUniformLocationWith1i(m_uniformTex0, 0);
    glUniform1f(m_uniformTime, m_time);
    
    //获取attribute变量
    Size size = getContentSize();
    float w = size.width;
    float h = size.height;
    
    GL::bindTexture2D(m_texture);//绑定纹理到槽位
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, w, h, 0);//截取屏幕数据到纹理
    glEnableVertexAttribArray(m_attributePosition);
    glDisableVertexAttribArray(m_attributeColor);
    //传递attribute变量
    GLfloat  vertices[12] = {
        0, 0, //左下0
        w, 0, //右下1
        w, h, //右上2
        0, 0, //左下0
        0, h, //左上3
        w, h, //右上2
    };
    glVertexAttribPointer(m_attributePosition, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttrib4fv(m_attributeColor, color);
    
    //绘制
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void ShaderNode::test(){
    //定点数据
    static GLfloat vertex[] =  {
        //顶点坐标x,y,z
        0.0f, 500.0f, 0.0f, //左下
        200.0f, 500.0f, 0.0f, //右下
        0.0f, 700.0f, 0.0f, //左上
        200.0f, 700.0f, 0.0f, //右上
    };
    
    static GLfloat coord[] = {
        //纹理坐标s,t
        0.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
    };
    
    static GLfloat color[] = {
        //颜色：r,g,b,a
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
    };
    
    //初始化纹理
    static Texture2D* texture2d = NULL;
    if (!texture2d) {
        texture2d = Director::getInstance()->getTextureCache()->addImage("HelloWorld.png");
        coord[2] = coord[6] = texture2d->getMaxS();
        coord[1] = coord[3] = texture2d->getMaxT();
    }
    //设置着色器
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);
    texture2d->getGLProgram()->use();
    texture2d->getGLProgram()->setUniformsForBuiltins();
    
    //绑定纹理
    GL::bindTexture2D(texture2d->getName());
    
    //设置定点数组
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, vertex);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, 0, coord);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, color);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    //通知cocos2d-x 的renderer，让它在合适的时候调用这些OpenGL命令
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 4);
    //如果出错了，可以使用这个函数来获取出错信息
    CHECK_GL_ERROR_DEBUG();
    
}

ShaderNode* ShaderNode::getInstance(const char* vert, const char* frag){
    ShaderNode* node=new ShaderNode();
    if (node && node->initWithVertex(vert,frag))
    {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return NULL;
}
