//
//  WaveFilter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#include "WaveFilter.h"

WaveFilter::WaveFilter()
{
    m_time = 0;
    Size tmp = Director::getInstance()->getWinSize();
    m_resolution.width = tmp.width;
    m_resolution.height = tmp.height;
    this->m_shaderName = "Filter_Wave";
}


void WaveFilter::update()
{
    auto glprogramstate = m_Sprite->getGLProgramState();
    
    if (glprogramstate) {
        
         m_time += 1.0f/60.0f;
        
        glprogramstate->setUniformFloat(u_time,m_time);
        CHECK_GL_ERROR_DEBUG();
        glprogramstate->setUniformVec2(u_resolution, Vec2(m_resolution.width,m_resolution.height));
        CHECK_GL_ERROR_DEBUG();
    }
}

void WaveFilter::loadShader()
{
    GLProgram* program = new GLProgram();
    program->initWithFilenames("wave.vsh","wave.fsh");
    setProgram(program);
    program->autorelease();
}

void WaveFilter::bindAttributes()
{
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
}

void WaveFilter::bindUniforms(){
    
    u_resolution = getProgram()->getUniformLocationForName("resolution");
    CHECK_GL_ERROR_DEBUG();
    
    u_time = getProgram()->getUniformLocationForName("time");
    CHECK_GL_ERROR_DEBUG();
    
}

void WaveFilter::setResolution(float pWidth, float pHeight){
    m_resolution.width = pWidth;
    m_resolution.height = pHeight;
}

void WaveFilter::setResolution(cocos2d::Size &resolution){
    m_resolution.width = resolution.width;
    m_resolution.height = resolution.height;
}


