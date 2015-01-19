//
//  FlashFilter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-16.
//
//

#ifndef __MyPlane__FlashFilter__
#define __MyPlane__FlashFilter__

#include "Filter.h"

class FlashFilter : public Filter
{
public:
    FlashFilter(); 
    
    virtual void setIntervalFrame(int intervalFrame);
    virtual void update();
    
    
private:
    
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
    
    int m_currentFrameCount;
    int m_frameInterval;
    float m_alpha;
    GLint u_alpha;
};

REGISTER_CLASS(Filter,FlashFilter);

#endif /* defined(__MyPlane__FlashFilter__) */
