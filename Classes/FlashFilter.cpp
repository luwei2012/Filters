//
//  FlashFilter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#include "FlashFilter.h"


FlashFilter::FlashFilter()
{
    m_frameInterval = 5;
    m_currentFrameCount = 0;
    m_alpha = 0;
    this->m_shaderName = "Filter_Flash";
}

void FlashFilter::setIntervalFrame( int intervalFrame )
{
    m_frameInterval = intervalFrame;
    m_currentFrameCount = 0;
}


void FlashFilter::update()
{
    auto glprogramstate = m_Sprite->getGLProgramState();
    
    if (glprogramstate) {
        
        if(m_currentFrameCount >= m_frameInterval)
        {
            m_alpha = m_alpha >= 1 ? 0 : m_alpha + 0.1;
            m_currentFrameCount = 0;
        }
        
        m_currentFrameCount++;
        
        glprogramstate->setUniformFloat(u_alpha,m_alpha);
    }
    
}

void FlashFilter::loadShader()
{
    GLProgram* program = new GLProgram();
    program->initWithFilenames("flash.vsh","flash.fsh");
    setProgram(program);
    program->autorelease();
}

void FlashFilter::bindAttributes()
{
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
}

void FlashFilter::bindUniforms()
{
    u_alpha = getProgram()->getUniformLocationForName("u_alpha");
}


