//  GrayFilter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#ifndef __MyPlane__GrayFilter__
#define __MyPlane__GrayFilter__

#include "Filter.h"

class GrayFilter : public Filter
{
public:
    GrayFilter();
    virtual void setColor(Color4F color);
    virtual void setColor(float r, float g, float b, float a);
    virtual void update();
    
private:
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
    
    Color4F m_color;
    GLint u_color;
};

REGISTER_CLASS(Filter,GrayFilter);

#endif /* defined(__MyPlane__GrayFilter__) */
