//
//  GodRayFilter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#ifndef __MyPlane__GodRayFilter__
#define __MyPlane__GodRayFilter__

#include "Filter.h"

class GodRayFilter : public Filter
{
public:
    GodRayFilter();
    
    virtual void setLightPos(float x, float y);
    virtual void update();
    
private:
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
    Point m_lightPos;
    float m_deltaTime;
    bool m_useUserPos;
    GLint  u_time;
    GLint  u_useParamPos;
    GLint  u_localPos;
};

REGISTER_CLASS(Filter,GodRayFilter);
#endif /* defined(__MyPlane__GodRayFilter__) */
