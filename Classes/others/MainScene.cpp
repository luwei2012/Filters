//
//  MainScene.cpp
//  MyStudy
//
//  Created by 陆伟 on 14-12-24.
//
//
#include <SimpleAudioEngine.h>
#include "MainScene.h"
#include <iostream>
#include "HelloWorldScene.h"
#include "Bullet.h"

#define BACKGROUND_SPPEND 1000
#define SCROLL_SPEED 0.5

using namespace std;

MainScene* MainScene::mainScene=NULL;

MainScene* MainScene::getInstance(){
    if (mainScene!=NULL) {
        return mainScene;
    }
    return NULL;
}

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    isEnded = false;
    mainScene = this;
    Size visibleSize = Director::getInstance()->getWinSize();
    //背景地图
    bg1 = Sprite::create("map.png");
    bg2 = Sprite::create("map.png");
    
    bg1->setPosition(Vec2( visibleSize.width*0.5 ,
                          bg1->getContentSize().height*0.5 ));
    //最后-1是为了防止图片交界处出现裂缝
    bg2->setPosition(Vec2( visibleSize.width*0.5 ,
                          ( bg1->getContentSize().height+bg2->getContentSize().height*0.5)));
    addChild(bg1);
    addChild(bg2);
    //背景循环
    scheduleUpdate();
    //添加音乐
//    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("gameMusic.mp3",true);
    
    //主角
    auto player = Player::createPlayer("player.png");
    player->setTag(0);
    
    addChild(player);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);//不向下传递触摸
    listener->onTouchBegan = [](Touch* touch, Event* event){
        auto target = MainScene::getInstance()->getChildByTag(0);
        target->setPosition(touch->getLocation());
        return true;
    };
    
    //拖动精灵移动
    listener->onTouchMoved = [](Touch* touch, Event* event){
        auto target = MainScene::getInstance()->getChildByTag(0);
        target->setPosition(touch->getLocation());
    };
    
    listener->onTouchEnded = [=](Touch* touch, Event* event){
        auto target = MainScene::getInstance()->getChildByTag(0);
        target->setPosition(touch->getLocation());
    };
    dispatcher->addEventListenerWithSceneGraphPriority(listener,this);
    
    schedule(schedule_selector(MainScene::autoCreateBullet), 0.15);
    schedule(schedule_selector(MainScene::autoCreateEnemy), 1.0);
    
    numbers = NumberScrollLabel::createLabel(3,60,SCROLL_SPEED);
    numbers->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    
    addChild(numbers);
    schedule(schedule_selector(MainScene::autoScrollNumber), SCROLL_SPEED);
    return true;
}

void MainScene::update(float time){
    Size visibleSize = Director::getInstance()->getWinSize();
    
    bg1->setPosition(bg1->getPosition()-Vec2(0,BACKGROUND_SPPEND*time));
    
    bg2->setPosition(bg2->getPosition()-Vec2(0,BACKGROUND_SPPEND*time));
    
    if(bg1->getPositionY()<= -bg1->getContentSize().height*0.5){
        bg1->setPosition(Vec2( visibleSize.width*0.5,bg2->getPositionY()+bg2->getContentSize().height*0.5+bg1->getContentSize().height*0.5));
    }
    if(bg2->getPositionY()<= -bg2->getContentSize().height*0.5){
        bg2->setPosition(Vec2( visibleSize.width*0.5,bg1->getPositionY()+bg2->getContentSize().height*0.5+bg1->getContentSize().height*0.5));
    }
    
}

void MainScene::onExit(){
    //解除更新
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    this->unscheduleUpdate();
    CCLayer::onExit();
}

void MainScene::autoCreateEnemy(float dt){
    int randomCount=CCRANDOM_0_1()*10;//随机本次创建enemy的个数
    for (int i=0; i<randomCount; i++) {
        int random=CCRANDOM_0_1()*10;
        Enemy *enemy=NULL;
//        int randomType=CCRANDOM_0_1()*10;
        int randomType=1;
        //随机怪的贴图
        const char* name;
        if(random>=0 && random<=2)
        {
            name="enemy_bug.png";
        }
        else if(random>=3 && random<=6)
        {
            name="enemy_duck.png";
        }
        else if(random>=7 && random<=10)
        {
            name="enemy_pig.png";
        }
        //随机类型
        if (randomType%2==0) {
            randomType=0;
        }
        else
        {
            randomType=1;
        }
        enemy=Enemy::createEnemy(name,randomType);
        arrayEnemy.pushBack(enemy);
        addChild(enemy);
    }
}

void MainScene::winGame(){
    if (!isEnded) {
        isEnded = true;
        //添加胜利界面
        Size size=Director::getInstance()->getWinSize();
        LayerColor *layer=LayerColor::create(Color4B(0, 0, 0, 190),size.width,size.height);
        auto sp=Sprite::createWithSpriteFrameName("game_win.png");
        sp->setPosition(Point(size.width*0.5,size.height*0.5));
        layer->addChild(sp);
        addChild(layer,100);
        
        //添加一个按钮用于返回menu
        auto ttback=Label::createWithTTF("Back", "fonts/MarkerFelt.ttf", 100);
        auto menuLabel=MenuItemLabel::create(ttback, [&](Ref *sender) {
            // do something. Item "sender" clicked
            MainScene::getInstance()->unscheduleAllSelectors();
            //继续游戏
            Director::getInstance()->resume();
            //切换到"菜单"场景
            Director::getInstance()->replaceScene(HelloWorld::createScene());
        });
        menuLabel->setPosition(Point(0, -400));
        auto menu=Menu::create(menuLabel,NULL);
        addChild(menu,100);
        //解除更新
        Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
        //暂停游戏
        Director::getInstance()->pause();
    }
}

void MainScene::lostGame(){
    if (!isEnded) {
        //添加胜利界面
        Size size=Director::getInstance()->getWinSize();
        LayerColor *layer=LayerColor::create(Color4B(0, 0, 0, 190),size.width,size.height);
        auto sp=Sprite::createWithSpriteFrameName("game_lost.png");
        sp->setPosition(Point(size.width*0.5,size.height*0.5));
        layer->addChild(sp);
        addChild(layer,100);
        
        //添加一个按钮用于返回menu
        auto ttback=Label::createWithTTF("Back", "fonts/MarkerFelt.ttf", 100);
        auto menuLabel=MenuItemLabel::create(ttback, [&](Ref *sender) {
            // do something. Item "sender" clicked
            MainScene::getInstance()->unscheduleAllSelectors();
            //继续游戏
            Director::getInstance()->resume();
            //切换到"菜单"场景
            Director::getInstance()->replaceScene(HelloWorld::createScene());
        });
        menuLabel->setPosition(Point(0, -400));
        auto menu=Menu::create(menuLabel,NULL);
        addChild(menu,100);
        //解除更新
        Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
        //暂停游戏
        Director::getInstance()->pause();
    }
}


void MainScene::autoCreateBullet(float dt){
    //主角子弹
    auto player= getChildByTag(0);
    addChild(Bullet::createBullet("p_bullet.png", 100,  player->getPosition()+Vec2(20-player->getContentSize().width*0.5,player->getContentSize().height*0.5)));
    addChild(Bullet::createBullet("p_bullet.png", 100,  player->getPosition()+Vec2(-20+player->getContentSize().width*0.5,player->getContentSize().height*0.5)));
    //子弹音效
//        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("effect_bullet.mp3");
}


void MainScene::autoScrollNumber(float dt){
    numbers->add(15);
}


Player* MainScene::getPlayer(){
    Player *player=(Player*)getChildByTag(0);
    return player;
}

MainScene::~MainScene(){
    CC_SAFE_RELEASE_NULL(bg1);
    CC_SAFE_RELEASE_NULL(bg2);
    CC_SAFE_RELEASE_NULL(numbers);
}



