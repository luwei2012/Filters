//
//  MainScene.h
//  MyStudy
//
//  Created by 陆伟 on 14-12-24.
//
//

#ifndef __MyStudy__MainScene__
#define __MyStudy__MainScene__

#include <stdio.h>
#include "cocos2d.h"
#include "Player.h"
#include "Enemy.h"
#include "NumberScrollLabel.h"

USING_NS_CC;

class MainScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    bool isEnded;
    Sprite* bg1;
    Sprite* bg2;
    NumberScrollLabel* numbers;
    Vector<Enemy*> arrayEnemy;
    Player* getPlayer();
    void update(float time);
    virtual void onExit();
    static MainScene* getInstance();
    CREATE_FUNC(MainScene);
    void winGame();
    void lostGame();
    ~MainScene();

private:
    static MainScene *mainScene;
    void autoCreateEnemy(float dt);//自动创建敌怪
    void autoCreateBullet(float dt);//自动创建子弹
    void autoScrollNumber(float dt);//自动滚动数字
};

#endif /* defined(__MyStudy__MainScene__) */
