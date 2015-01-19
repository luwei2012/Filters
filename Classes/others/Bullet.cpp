//
//  Bullet.cpp
//  MyPlane
//
//  Created by 陆伟 on 14-12-26.
//
//

#include "Bullet.h"
#include "MainScene.h"
#include "Bullet.h"
#include "SimpleAudioEngine.h"
#include "Player.h"
using namespace CocosDenshion;

Bullet *Bullet::createBullet(const char* _fileName,float _speed,Point _position)
{
    Bullet *bullet=new Bullet();
    if (bullet &&bullet->initWithSpriteFrameName(_fileName)) {
        bullet->autorelease();
        bullet->bulletInit(_speed, _position);
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return NULL;
}

void Bullet::bulletInit(float _speed,Point _position)
{
    speed=_speed;
    this->setPosition(_position);
    this->scheduleUpdate();
}
void Bullet::update(float time)
{
    //子弹向上运动
    this->setPosition(getPosition()+ Point(0, speed));
    bool flag = false;
    for (int i=0; i<(*(MainScene::getInstance())).arrayEnemy.size(); i++) {
        Enemy *enemy=(Enemy *)((*(MainScene::getInstance())).arrayEnemy.at(i));
        if (enemy->boundingBox().intersectsRect(this->boundingBox()))
        {
            //爆炸音效
//            SimpleAudioEngine::getInstance()->playEffect("effect_boom.mp3");
            
            //爆炸粒子效果
            ParticleSystemQuad *particle=ParticleSystemQuad::create("particle_boom.plist");
            particle->setPosition(enemy->getPosition());
            particle->setAutoRemoveOnFinish(true);
            MainScene::getInstance()->addChild(particle);
            
            //增加分数
            MainScene::getInstance()->getPlayer()->addScore(enemy->scoreValue);
            //添加杀人数
            MainScene::getInstance()->getPlayer()->addKillCount(1);
            //从敌人数组将被攻击的敌怪删除
            (*(MainScene::getInstance())).arrayEnemy.eraseObject(enemy);
            //删除子弹与敌怪
            MainScene::getInstance()->removeChild(enemy, true);
            flag = true;
            break;
        }
    } 
    Size size=Director::getInstance()->getWinSize();
    if (this->getPositionY()>size.height||flag) {
        MainScene::getInstance()->removeChild(this, true);
    }
}

void Bullet::onExit()
{
    this->unscheduleUpdate();
    CCSprite::onExit();
}