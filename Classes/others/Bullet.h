//
//  Bullet.h
//  MyPlane
//
//  Created by 陆伟 on 14-12-26.
//
//

#ifndef __MyPlane__Bullet__
#define __MyPlane__Bullet__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class Bullet:public Sprite
{
public:
    static Bullet *createBullet(const char* _fileName,float _speed,Point _position);
private:
    void bulletInit(float _speed,Point _position);
    void update(float time);
    float speed;
    
    virtual void onExit();
};

#endif /* defined(__MyPlane__Bullet__) */
