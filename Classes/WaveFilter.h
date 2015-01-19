//
//  WaveFilter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#ifndef __MyPlane__WaveFilter__
#define __MyPlane__WaveFilter__

#include "Filter.h"

class WaveFilter : public Filter
{
public:
    WaveFilter();
    
    virtual void update();
    virtual void setResolution(Size &resolution);
    virtual void setResolution(float pWidth, float pHeight);
private:
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
    
    float m_time;
    Size m_resolution;
    
    GLint u_time;
    GLint u_resolution;
};


REGISTER_CLASS(Filter,WaveFilter);
#endif /* defined(__MyPlane__WaveFilter__) */
