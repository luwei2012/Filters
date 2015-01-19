//
//  SpriteWithFilterWithFilter.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-17.
//
//

#include "SpriteWithFilter.h"

SpriteWithFilter::SpriteWithFilter(){
    _filter = nullptr;
}

SpriteWithFilter::~SpriteWithFilter()
{
    CC_SAFE_RELEASE_NULL(_filter);
}

SpriteWithFilter* SpriteWithFilter::createWithTexture(Texture2D *texture)
{
    SpriteWithFilter *spriteWithFilter = new (std::nothrow) SpriteWithFilter();
    if (spriteWithFilter && spriteWithFilter->initWithTexture(texture))
    {
        spriteWithFilter->autorelease();
        return spriteWithFilter;
    }
    CC_SAFE_DELETE(spriteWithFilter);
    return nullptr;
}

SpriteWithFilter* SpriteWithFilter::createWithTexture(Texture2D *texture, const Rect& rect, bool rotated)
{
    SpriteWithFilter *spriteWithFilter = new (std::nothrow) SpriteWithFilter();
    if (spriteWithFilter && spriteWithFilter->initWithTexture(texture, rect, rotated))
    {
        spriteWithFilter->autorelease();
        return spriteWithFilter;
    }
    CC_SAFE_DELETE(spriteWithFilter);
    return nullptr;
}

SpriteWithFilter* SpriteWithFilter::create(const std::string& filename)
{
    SpriteWithFilter *spriteWithFilter = new (std::nothrow) SpriteWithFilter();
    if (spriteWithFilter && spriteWithFilter->initWithFile(filename))
    {
        spriteWithFilter->autorelease();
        return spriteWithFilter;
    }
    CC_SAFE_DELETE(spriteWithFilter);
    return nullptr;
}

SpriteWithFilter* SpriteWithFilter::create(const std::string& filename, const Rect& rect)
{
    SpriteWithFilter *spriteWithFilter = new (std::nothrow) SpriteWithFilter();
    if (spriteWithFilter && spriteWithFilter->initWithFile(filename, rect))
    {
        spriteWithFilter->autorelease();
        return spriteWithFilter;
    }
    CC_SAFE_DELETE(spriteWithFilter);
    return nullptr;
}

SpriteWithFilter* SpriteWithFilter::createWithSpriteFrame(SpriteFrame *spriteFrame)
{
    SpriteWithFilter *spriteWithFilter = new (std::nothrow) SpriteWithFilter();
    if (spriteWithFilter && spriteWithFilter && spriteWithFilter->initWithSpriteFrame(spriteFrame))
    {
        spriteWithFilter->autorelease();
        return spriteWithFilter;
    }
    CC_SAFE_DELETE(spriteWithFilter);
    return nullptr;
}

SpriteWithFilter* SpriteWithFilter::createWithSpriteFrameName(const std::string& spriteFrameName)
{
    SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
    
#if COCOS2D_DEBUG > 0
    char msg[256] = {0};
    sprintf(msg, "Invalid SpriteFrameName: %s", spriteFrameName.c_str());
    CCASSERT(frame != nullptr, msg);
#endif
    
    return createWithSpriteFrame(frame);
}

SpriteWithFilter* SpriteWithFilter::create()
{
    SpriteWithFilter *spriteWithFilter = new (std::nothrow) SpriteWithFilter();
    if (spriteWithFilter && spriteWithFilter->init())
    {
        spriteWithFilter->autorelease();
        return spriteWithFilter;
    }
    CC_SAFE_DELETE(spriteWithFilter);
    return nullptr;
}

void SpriteWithFilter::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags){
    //do somthing
    if (_filter) {
        _filter->update();
    }
    Sprite::draw(renderer, transform, flags);
 
}

void SpriteWithFilter::setFilter(Filter *var){
    if (_filter != var) {
        CC_SAFE_RETAIN(var);
        CC_SAFE_RELEASE(_filter);
        _filter = var;
    }
    if(_filter){
        _filter->initWithSprite(this);
    }
}

Filter* SpriteWithFilter::getFilter(){
    return _filter;
}

 




