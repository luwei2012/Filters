//
//  ColorFlashFilter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#include "ColorFlashFilter.h"

ColorFlashFilter::ColorFlashFilter()
{
    m_color.r = 1.0;
    m_color.g = 0.0;
    m_color.b = 0.0;
    m_count = 0;
    m_interval = 1;
    m_shaderName = "Filter_ColorFlash";
}

void ColorFlashFilter::setColor( float r, float g, float b )
{
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
}

void ColorFlashFilter::setIntervalFrame( float interval )
{
    m_interval = interval;
    m_count = 0;
}


void ColorFlashFilter::update()
{
    auto glprogramstate = m_Sprite->getGLProgramState();
    
    if (glprogramstate) {
        
        m_count += m_interval;
        m_percent = (sin(m_count) + 1.0f) * 0.25f;
        
        Color4F c = Color4F(m_color.r * m_percent, m_color.g * m_percent, m_color.b * m_percent, 1);
        glprogramstate->setUniformVec3(m_location, Vec3(c.r,c.g,c.b));
        CHECK_GL_ERROR_DEBUG();
    }    
    
}

void ColorFlashFilter::loadShader()
{
    GLProgram* program = new GLProgram();
    program->initWithFilenames("colorFlash.vsh","colorFlash.fsh");
    setProgram(program);
    program->autorelease();
}

void ColorFlashFilter::bindAttributes()
{
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
}

void ColorFlashFilter::bindUniforms()
{
    m_location = getProgram()->getUniformLocationForName("u_color");
    CHECK_GL_ERROR_DEBUG();
}





