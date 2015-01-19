//
//  TestFilter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-17.
//
//

#include "TestFilter.h"
TestFilter::TestFilter(){
    this->m_shaderName = "Filter_TestFilter";
}



void TestFilter::loadShader()
{
    GLProgram* program = new GLProgram();
    program->initWithFilenames("test_gray.vsh","test_gray.fsh");
    setProgram(program);
    program->autorelease();
}

void TestFilter::bindAttributes()
{
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
    getProgram()->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
}

void TestFilter::bindUniforms()
{
    
}