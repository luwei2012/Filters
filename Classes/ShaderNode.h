//
//  ShaderNode.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-13.
//
//

#ifndef __MyPlane__ShaderNode__
#define __MyPlane__ShaderNode__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class ShaderNode : public Node{
    
public: 
    bool initWithVertex(const char* vert, const char* frag);
    void loadShaderVertex(const char* vert , const char* frag);
    virtual void update(float dt);
    virtual void setContentSize(const Size& var);
    void setColor(Color4F newColor);
    virtual void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);
    virtual void drawWaves();
    virtual void test();
    static ShaderNode* getInstance(const char* vert, const char* frag);
    CustomCommand m_customCommand;
private:
    //标示符
    GLuint m_uniformResolution,m_uniformTime,m_uniformTex0;
    GLuint m_attributeColor,m_attributePosition;
    //取值
    float m_time;
    Vec2 m_resolution;
    Vec2 m_center;
    GLuint m_texture;
    GLfloat color[4];
    
};

#endif /* defined(__MyPlane__ShaderNode__) */
