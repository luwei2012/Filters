//
//  MyWave.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-17.
//
//

#ifndef __MyPlane__MyWave__
#define __MyPlane__MyWave__

#include "Filter.h"

class MyWaveFilter : public Filter
{
public:
    MyWaveFilter();
    virtual void update();
    virtual void setContentSize(const Size& var);
    virtual void setContentSize(float width,float height);
    virtual void setColor(Color4F& var);
    virtual void setColor(float r,float g,float b,float a);
    
private:
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
    
protected:
    GLint u_time;
    GLint u_resolution;
    Color4F m_color;
    float m_time;
    Size m_resolution;
};

REGISTER_CLASS(Filter,MyWaveFilter);

#endif /* defined(__MyPlane__MyWave__) */
