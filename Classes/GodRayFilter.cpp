//
//  GodRayFilter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#include "GodRayFilter.h"

GodRayFilter::GodRayFilter(){
    m_deltaTime = 0;
    m_useUserPos = false;
    this->m_shaderName = "Filter_GodRay";
}


void GodRayFilter::setLightPos( float x, float y )
{
    m_lightPos.setPoint(x,y);
    m_useUserPos = true;
}



void GodRayFilter::update()
{
    
    auto glprogramstate = m_Sprite->getGLProgramState();
    
    if (glprogramstate) {
        
        glprogramstate->setUniformFloat(u_time,m_deltaTime);
        CHECK_GL_ERROR_DEBUG();
        glprogramstate->setUniformInt(u_useParamPos,m_useUserPos);
        CHECK_GL_ERROR_DEBUG();
        glprogramstate->setUniformVec2(u_localPos,Vec2(m_lightPos.x,m_lightPos.y));
        CHECK_GL_ERROR_DEBUG();
        m_useUserPos = false;
    }
    
}

void GodRayFilter::loadShader()
{
    GLProgram* program = new GLProgram();
    program->initWithFilenames("godRay.vsh","godRay.fsh");
    setProgram(program);
    program->autorelease();
}

void GodRayFilter::bindAttributes()
{
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
}

void GodRayFilter::bindUniforms()
{
    m_deltaTime += 0.0166;
    
    u_time = getProgram()->getUniformLocationForName("u_time");
    CHECK_GL_ERROR_DEBUG();
    
    u_useParamPos = getProgram()->getUniformLocationForName("u_useParamPos");
    CHECK_GL_ERROR_DEBUG();
    
    u_localPos = getProgram()->getUniformLocationForName("u_localPos");
    CHECK_GL_ERROR_DEBUG();
    
}






