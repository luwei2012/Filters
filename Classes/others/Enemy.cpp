//
//  Enemy.cpp
//  MyPlane
//
//  Created by 陆伟 on 14-12-26.
//
//

#include "Enemy.h"
#include "MainScene.h"

Enemy  *Enemy::createEnemy(const char* fileName,int _type)
{
    Enemy *enemy=new Enemy();
    if (enemy &&enemy->initWithFile(fileName))
    {
        enemy->autorelease();
        enemy->enemyInit(fileName, _type);
        return enemy;
    }
    CC_SAFE_DELETE(enemy);
    return NULL;
}
void Enemy::enemyInit(const char*fileName,int _type)
{
    type=_type;
    createAnimate(fileName, 10);
    Size size=Director::getInstance()->getWinSize();
    if (_type==0) {
        scoreValue=198;
    }
    else if(_type==1)
    {
        scoreValue=428;
    }
    else if(_type==2)
    {
        scoreValue=908;
    }
    //X在屏幕内随机位置
    setPosition(Vec2(0, size.height+this->getContentSize().height));

    //敌人逻辑
    this->scheduleUpdate();
}
//敌人逻辑
void Enemy::update(float time)
{
    switch (type) {
        case 0:
            this->setPosition(this->getPosition()+ Vec2(0,-10));
            break;
        case 1:
        {
            //判断防止重复调用此动作，保证此逻辑只会执行一次
            if (isActed) {
                break;
            }
            isActed=true;
            Size winsize = Director::getInstance()->getWinSize();
            ccBezierConfig bezier0;
            bezier0.controlPoint_1=Point(0,winsize.height+this->getContentSize().height);
            bezier0.controlPoint_2=Point(winsize.width*0.4,winsize.height*0.92);
            bezier0.endPosition=Point(winsize.width*0.5,winsize.height*0.5);
            FiniteTimeAction* beizerAction = BezierTo::create(1.5,bezier0);
            
            ccBezierConfig bezier1;
            bezier1.controlPoint_1=Point(winsize.width*0.5,winsize.height*0.5);
            bezier1.controlPoint_2=Point(winsize.width*0.6,winsize.height*0.08);
            bezier1.endPosition=Point(winsize.width,-getContentSize().height);
            FiniteTimeAction* beizerAction1 = BezierTo::create(1.5,bezier1);
            
            this->runAction(Sequence::create(beizerAction,beizerAction1, NULL));
        }
            break;
        case 2:
        {
            if (isActed) {
                break;
            }
            isActed=true;
            Size winsize = Director::getInstance()->getWinSize();
            ccBezierConfig bezier0;
            bezier0.controlPoint_1=Point(0,winsize.height);
            bezier0.controlPoint_2=Point(winsize.width*0.125,winsize.height*0.8);
            bezier0.endPosition=Point(winsize.width*0.25,winsize.height*0.6);
            FiniteTimeAction* beizerAction = BezierTo::create(1.5,bezier0);
            
            ccBezierConfig bezier1;
            bezier1.controlPoint_1=Point(winsize.width*0.25,winsize.height*0.6);
            bezier1.controlPoint_2=Point(winsize.width*0.375,winsize.height*0.4);
            bezier1.endPosition=Point(winsize.width*0.5,winsize.height*0.2);
            FiniteTimeAction* beizerAction1 = BezierTo::create(1.5,bezier1);
            
            ccBezierConfig bezier2;
            bezier2.controlPoint_1=Point(winsize.width*0.5,winsize.height*0.2);
            bezier2.controlPoint_2=Point(winsize.width*0.625,winsize.height*0.4);
            bezier2.endPosition=Point(winsize.width*0.75,winsize.height*0.6);
            FiniteTimeAction* beizerAction2 = BezierTo::create(1.5,bezier2);
            
            ccBezierConfig bezier3;
            bezier3.controlPoint_1=Point(winsize.width*0.75,winsize.height*0.6);
            bezier3.controlPoint_2=Point(winsize.width*0.875,winsize.height*0.8);
            bezier3.endPosition=Point(winsize.width,winsize.height);
            FiniteTimeAction* beizerAction3 = BezierTo::create(1.5,bezier3);
            
            this->runAction(Sequence::create(beizerAction,beizerAction1,beizerAction2,beizerAction3, NULL));
        }
            break;
        default:
            break;
    }
    auto player= MainScene::getInstance()->getPlayer();
    if (!player->isDead) {
        if (player->boundingBox().intersectsRect(this->boundingBox()))
        {
            player->downHp();
        }
    }
    
    if (this->getPositionY()<-this->getContentSize().height) {
        (*(MainScene::getInstance())).arrayEnemy.eraseObject(this);
        this->getParent()->removeChild(this, true);
    }
    
    
}
//敌人成动态表现
void Enemy::createAnimate(const char* fileName,int allCount)
{
    Animation *animation=Animation::create();
    auto texture = Director::getInstance()->getTextureCache()->addImage(fileName);
    
    int eachWidth=texture->getContentSize().width/allCount;
    for (int i=0; i<allCount; i++) {
        animation->addSpriteFrameWithTexture(texture, Rect(i*eachWidth, 0, eachWidth, this->getContentSize().height));
    }
    animation->setDelayPerUnit(0.03f);
    animation->setRestoreOriginalFrame(true);
    animation->setLoops(-1);
    FiniteTimeAction *animate=Animate::create(animation);
    this->runAction(animate);
}

void Enemy::onExit()
{
    this->unscheduleUpdate();
    CCSprite::onExit();
}
