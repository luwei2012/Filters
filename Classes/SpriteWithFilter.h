//
//  SpriteWithFilter.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-17.
//
//

#ifndef __MyPlane__SpriteWithFilter__
#define __MyPlane__SpriteWithFilter__

#include "Filter.h"

class SpriteWithFilter : public Sprite{
    
public:
    
    SpriteWithFilter();
    
    virtual ~SpriteWithFilter();
    
    static SpriteWithFilter* create();
    
    static SpriteWithFilter* create(const std::string& filename);
    
    static SpriteWithFilter* create(const std::string& filename, const Rect& rect);
    
    static SpriteWithFilter* createWithTexture(Texture2D *texture);
    
    static SpriteWithFilter* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false);
    
    static SpriteWithFilter* createWithSpriteFrame(SpriteFrame *spriteFrame);
    
    static SpriteWithFilter* createWithSpriteFrameName(const std::string& spriteFrameName);
    
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
         
    CC_PROPERTY(Filter*,_filter,Filter);//ID
    
protected:
    
    
};

#endif /* defined(__MyPlane__SpriteWithFilter__) */
