//
//  MyWave.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-17.
//
//

#include "MyWave.h"
MyWaveFilter::MyWaveFilter(){
    this->m_shaderName = "Filter_MyWaveFilter";
    Size size = Director::getInstance()->getWinSize();
    m_resolution.width = size.width;
    m_resolution.height = size.height;
    m_color.r = 0.5;
    m_color.g = 0.5;
    m_color.b = 0.0;
    m_color.a = 1.0;
    m_time = 0;
}

void MyWaveFilter::update(){
    auto glprogramstate = m_Sprite->getGLProgramState();
    
    if (glprogramstate) {
        
        glprogramstate->setUniformVec2(u_resolution, Vec2(m_resolution.width,m_resolution.height));
        CHECK_GL_ERROR_DEBUG();
        
        glprogramstate->setUniformFloat(u_time, m_time);
        CHECK_GL_ERROR_DEBUG();
        
        
    }
    m_time += 0.015;
}

void MyWaveFilter::loadShader()
{
    GLProgram* program = new GLProgram();
    program->initWithFilenames("my_wave.vsh","my_wave.fsh");
    setProgram(program);
    program->autorelease();
}

void MyWaveFilter::bindAttributes()
{
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
}

void MyWaveFilter::bindUniforms()
{
    u_time = getProgram()->getUniformLocationForName("time");
    u_resolution = getProgram()->getUniformLocationForName("resolution");
}


void MyWaveFilter::setColor(cocos2d::Color4F &var){
    m_color.r = var.r;
    m_color.g = var.g;
    m_color.b = var.b;
    m_color.a = var.a;
}

void MyWaveFilter::setColor(float r, float g, float b, float a){
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
    m_color.a = a;
}

void MyWaveFilter::setContentSize(const cocos2d::Size &var){
    m_resolution = var;
    m_Sprite->setContentSize(m_resolution);
}

void MyWaveFilter::setContentSize(float width, float height){
    m_resolution = Size(width, height);
    m_Sprite->setContentSize(m_resolution);
}





