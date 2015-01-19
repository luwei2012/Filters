//
//  Filter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-15.
//
//

#ifndef __MyPlane__Filter__
#define __MyPlane__Filter__

#include "FilterFactory.h"
#include "cocos2d.h"

USING_NS_CC;

class Filter : public Ref{
    
public:
    Filter();
    virtual ~Filter(void);
    
    virtual void initWithSprite(Sprite* node);
    virtual void update();
    
    CC_SYNTHESIZE_RETAIN(GLProgram*,_program,Program);//ID
    
private:
    
    virtual void initProgram();
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
    
protected:
    
    const char* m_shaderName;
    
    Sprite* m_Sprite;
    
};


#endif /* defined(__MyPlane__Filter__) */
