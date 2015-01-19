//
//  Enemy.h
//  MyPlane
//
//  Created by 陆伟 on 14-12-26.
//
//

#ifndef __MyPlane__Enemy__
#define __MyPlane__Enemy__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

class Enemy:public Sprite
{
public:
    static Enemy *createEnemy(const char* fileName,int _type);
    //价值多少分
    int scoreValue;
private:
    //初始化
    void enemyInit(const char*fileName,int _type);
    
    //敌人成动态表现
    void createAnimate(const char* fileName,int allCount);
    //敌人逻辑
    void update(float time);
    //是否已经运行过了
    bool isActed;
    //当前敌人类型
    int type;
    
    virtual void onExit();
};

#endif /* defined(__MyPlane__Enemy__) */
