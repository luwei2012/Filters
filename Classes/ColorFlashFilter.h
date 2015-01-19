//
//  ColorFlashFilter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#ifndef __MyPlane__ColorFlashFilter__
#define __MyPlane__ColorFlashFilter__

#include "Filter.h"


class ColorFlashFilter : public Filter
{
public:
    ColorFlashFilter();
    
    virtual void setColor(float r, float g, float b);
    virtual void setIntervalFrame(float interval);
    virtual void update();
    
private:
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
    
    float m_count;
    float m_interval;
    GLint m_location;
    Color4F m_color;
    float m_percent;
};

REGISTER_CLASS(Filter,ColorFlashFilter);

#endif /* defined(__MyPlane__ColorFlashFilter__) */
