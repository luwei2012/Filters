//
//  Filter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-15.
//
//

#include "Filter.h"

Filter::Filter()
:m_shaderName(GLProgram::SHADER_NAME_POSITION_TEXTURE){
    _program = nullptr;
}


Filter::~Filter(){
    //只有m_program是属于Filter的  需要释放
    CC_SAFE_RELEASE_NULL(_program);
}

void Filter::initWithSprite(Sprite* node){
    m_Sprite = node;
    initProgram();
    node->setGLProgram(_program);
    CHECK_GL_ERROR_DEBUG();
}

void Filter::update(){
    //更新uniform值
}

void Filter::initProgram(){
    //判断是否初始化过
    if (!_program) {
        //没有初始化过  先从缓存里面找
        GLProgram* tmp = GLProgramCache::getInstance()->getGLProgram(m_shaderName);
        if (!tmp) {
            //缓存里面没有找到   载入着色器
            loadShader();
            //添加进缓存中
            GLProgramCache::getInstance()->addGLProgram(_program,m_shaderName);
        }else{
            //缓存里面已经有了
            setProgram(tmp);
        }
        //绑定attribute变量
        this->bindAttributes();
        _program->link();
        
        //绑定uniform变量
        _program->updateUniforms();
        this->bindUniforms();

    }
}

void Filter::loadShader(){}


void Filter::bindAttributes(){}


void Filter::bindUniforms(){}




