//
//  Player.cpp
//  MyStudy
//
//  Created by 陆伟 on 14-12-25.
//
//

#include "Player.h"
#include "MainScene.h"
#define HP_GAP 1

typedef enum
{
    tag_player=0,//主角
    tag_playerHp1,//血量1
    tag_playerHp2,//血量2
    tag_playerHp3,//血量3
    tag_scoreLabelTTF,//分数文字
    tag_scoreTTF,//分数
    tag_killsCountLabelTTF,//杀敌数文字
    tag_killsCountTTF,//杀敌数
}tagWorld;

Player* Player::createPlayer(const char *fileName){
    Player* player = new Player();
    if(player && player->initWithSpriteFrameName("player.png")){
        player->autorelease();
        player->playerInit();
        return player;
    }
    CC_SAFE_DELETE(player);
    return NULL;
}


void Player::playerInit(){
    Size visibleSize = Director::getInstance()->getWinSize();
    this->setPosition(Vec2( visibleSize.width*0.5, this->getContentSize().height*0.5));
    //血和分数
    hpMax = 3;
    hp = 3;
    score = 0;
    strongTime = 2 * 60;//无敌时间2秒
    
    for(int i = 0;i<3; i++){
        auto hpSprite = Sprite::createWithSpriteFrameName("icon_hp.png");
        hpSprite->setPosition(Vec2( visibleSize.width-hpSprite->getContentSize().width*0.5-i * (getContentSize().width+HP_GAP),visibleSize.height-getContentSize().width*0.5));
        hpSprite->setTag(i+1);
        MainScene::getInstance()->addChild(hpSprite);
    }
    
    //初始化“分数”文字加入layer中
    auto label=Label::createWithTTF("Score:", "fonts/MarkerFelt.ttf", 60);
    label->setPosition(Vec2(label->getContentSize().width*0.5,visibleSize.height-label->getContentSize().height));
    MainScene::getInstance()->addChild(label,10,tag_scoreLabelTTF);
    
    string strScore=Conver2String(score);
    auto labelScores=Label::createWithTTF(strScore.c_str(), "fonts/MarkerFelt.ttf", 60);
    labelScores->setPosition(Vec2(label->getContentSize().width+labelScores->getContentSize().width*0.5, visibleSize.height-label->getContentSize().height));
    labelScores->setColor(Color3B(255, 255, 0));
    MainScene::getInstance()->addChild(labelScores,10,tag_scoreTTF);
    
    
    //杀敌人数
    auto labelKill=Label::createWithTTF("Destroy:", "fonts/MarkerFelt.ttf", 60);
    labelKill->setPosition(Vec2(labelKill->getContentSize().width*0.5,visibleSize.height-label->getContentSize().height-labelKill->getContentSize().height));
    MainScene::getInstance()->addChild(labelKill,10,tag_killsCountLabelTTF);
    
    string strKillCount=Conver2String(killCount);
    strKillCount+="/1000";
    auto labelKillCount=Label::createWithTTF(strKillCount.c_str(), "fonts/MarkerFelt.ttf", 60);
    labelKillCount->setPosition(Vec2(labelKill->getContentSize().width+labelKillCount->getContentSize().width*0.5, visibleSize.height-label->getContentSize().height-labelKill->getContentSize().height));
    labelKillCount->setColor(Color3B(255, 255, 0));
    MainScene::getInstance()->addChild(labelKillCount,10,tag_killsCountTTF);
    
}

void Player::downHp(){
    if(isStrong){
        return;
    }
    hp-=1;
    if (hp<=0) {
        setVisible(false);
        isDead=true;
        //储存分数
        int oldScore = atoi(UserDefault::getInstance()->getStringForKey("user_score","-1").c_str());
        if (score>oldScore) {
            UserDefault::getInstance()->setStringForKey("user_score", Conver2String(score));
        }
        MainScene::getInstance()->removeChildByTag(hpMax,true);
        MainScene::getInstance()->lostGame();
    }else{
        MainScene::getInstance()->removeChildByTag(hpMax-hp,true);
    }
    isStrong = true;
    strongCount = 0;
    schedule(schedule_selector(Player::strongIng));
}

void Player::strongIng(float dt){
    strongCount++;
    if(strongCount%strongTime==0){
        this->setVisible(true);
        isStrong=false;
        this->unschedule(schedule_selector(Player::strongIng));
    }else{
        if (strongCount%3==0) {
            this->setVisible(false);
        }else{
            this->setVisible(true);
        }
    }
}

void Player::addScore(float value){
    score+=value;
    string strScore=Conver2String(score);
    auto ttf = (Label*)MainScene::getInstance()->getChildByTag(tag_scoreTTF);
    auto ttfLabel = (Label*)MainScene::getInstance()->getChildByTag(tag_scoreLabelTTF);
    ttf->setString(strScore.c_str());
    ttf->setPosition(Vec2(ttfLabel->getContentSize().width+ttf->getContentSize().width*0.5, ttf->getPosition().y));
}

void Player::addKillCount(float value){
    killCount+=value;
    string strKillCount = Conver2String(killCount);
    strKillCount+="/1000";
    auto ttf = (Label*)MainScene::getInstance()->getChildByTag(tag_killsCountTTF);
    auto ttfLabel = (Label*)MainScene::getInstance()->getChildByTag(tag_killsCountLabelTTF);
    ttf->setString(strKillCount.c_str());
    ttf->setPosition(Vec2(ttfLabel->getContentSize().width+ttf->getContentSize().width*0.5, ttf->getPosition().y));
    if(killCount>=1000){
        //储存分数
        int oldSore = atoi(UserDefault::getInstance()->getStringForKey("user_score","-1").c_str());
        if(score>oldSore){
            UserDefault::getInstance()->setStringForKey("user_score", Conver2String(score));
            UserDefault::getInstance()->flush();
        }
        //调用胜利页面
        MainScene::getInstance()->winGame();
    }
}




