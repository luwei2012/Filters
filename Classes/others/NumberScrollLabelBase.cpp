//
//  NumberScrollLabelBase.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-6.
//
//

#include "NumberScrollLabelBase.h"

NumberScrollLabelBase* NumberScrollLabelBase::createLabel(int numberSize,float speed)
{
    NumberScrollLabelBase* label=new NumberScrollLabelBase();
    if (label &&label->init(numberSize,speed))
    {
        label->autorelease();
        return label;
    }
    CC_SAFE_DELETE(label);
    return NULL;
}
bool NumberScrollLabelBase::init(int numberSize,float speed)
{
    m_numberSize = numberSize;
    m_speed = speed;
    m_visibleNode = Node::create();
    this->addChild(m_visibleNode);
    for (int i = 0; i<10; i++) {
        char str[2];
        str[0]='0'+i;
        str[1]='\0';
        auto label=Label::createWithTTF(str, "fonts/MarkerFelt.ttf", numberSize);
        label->setTag(i);
        label->setAnchorPoint(Point::ZERO);
        label->setPosition(Point(0,numberSize*i));
        m_visibleNode->addChild(label);
        labels.pushBack(label);
    }
    return true;
}

void NumberScrollLabelBase::setNumber(int var,float speed){
    this->stopAllActions();
    //创建两个动画，当前的数字下移，需要的数字落下
    Label* currentLabel = labels.at(currentNumber);
    Point moveToPosition1 = Point(0,-m_numberSize);
    //当前的数字下移
    MoveTo* moveAction1 = MoveTo::create(speed<0?m_speed:speed, moveToPosition1);
    //需要的数字落下
    Label* targetLabel = labels.at(var);
    //首先重新设置目标lable的位置，应该仅次于currentLabel
    targetLabel->setPosition(Point(0,m_numberSize));
    Point moveToPosition2 = Point(0,0);
    MoveTo* moveAction2 = MoveTo::create(speed<0?m_speed:speed, moveToPosition2);
    currentLabel->runAction(moveAction1);
    targetLabel->runAction(moveAction2);
    currentNumber = var;
}

NumberScrollLabelBase::~NumberScrollLabelBase(){
    CC_SAFE_RELEASE_NULL(m_visibleNode);
}


