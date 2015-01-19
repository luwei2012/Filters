//
//  GrayFilter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#include "GrayFilter.h"

GrayFilter::GrayFilter()
{
    m_color.r = 0.299f;
    m_color.g = 0.587f;
    m_color.b = 0.114f;
    m_color.a = 1.0f;
    this->m_shaderName = "Filter_Gray";
}

void GrayFilter::setColor( Color4F color )
{
    m_color = color;
}

void GrayFilter::setColor( float r, float g, float b, float a )
{
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
    m_color.a = a;
}

void GrayFilter::loadShader()
{
    GLProgram* program = new GLProgram();
    program->initWithFilenames("gray.vsh","gray.fsh");
    setProgram(program);
    program->autorelease();
}

void GrayFilter::bindAttributes()
{
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
}

void GrayFilter::bindUniforms()
{
    u_color = getProgram()->getUniformLocationForName("u_paramColor");
    CHECK_GL_ERROR_DEBUG();
}


void GrayFilter::update()
{
    auto glprogramstate = m_Sprite->getGLProgramState();
    
    if (glprogramstate) {
        
        glprogramstate->setUniformVec4(u_color, Vec4(m_color.r,m_color.g,m_color.b,m_color.a));
        CHECK_GL_ERROR_DEBUG();
    }
    
}



