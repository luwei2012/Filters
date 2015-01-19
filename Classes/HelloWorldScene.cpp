#include "HelloWorldScene.h"
#include <SimpleAudioEngine.h>
#include <iostream>
#include "ShaderNode.h"
#include "SpriteWithFilter.h"

using namespace std;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // init spriteSheet
    
    Size visibleSize = Director::getInstance()->getWinSize();
    
//    auto background = Sprite::create("Sea.jpg");
//    
//    background->setPosition(Vec2(visibleSize.width/2 , visibleSize.height/2));
//    
//    addChild(background);
    
    auto hello = SpriteWithFilter::create("HelloWorld.png");
    
    hello->setPosition(Vec2(visibleSize.width/2 , visibleSize.height/2));
    
    Filter* filter = CREATE_CLASS(Filter, "MyWaveFilter");
    
    hello->setFilter(filter);
    
    addChild(hello);
    
    filter->autorelease();
    
//    auto shaderNode = ShaderNode::getInstance("test_wave.vsh", "test_wave.fsh");
//    
//    shaderNode->setPosition(Vec2(visibleSize.width/2 , visibleSize.height/2));
//    
//    addChild(shaderNode);
   
    return true;
}

