//
//  NumberScrollLabel.cpp
//  MyPlane
//
//  Created by 陆伟 on 15-1-6.
//
//

#include "NumberScrollLabel.h"
#include "NumberScrollLabelBase.h"

NumberScrollLabel* NumberScrollLabel::createLabel(int numberCnt,int numberSize,float speed)
{
    NumberScrollLabel* label=new NumberScrollLabel();
    if (label &&label->init(numberCnt,numberSize,speed))
    {
        label->autorelease();
        return label;
    }
    CC_SAFE_DELETE(label);
    return NULL;
}
bool NumberScrollLabel::init(int numberCnt,int numberSize,float speed)
{
    m_numberCnt = numberCnt;
    m_number = 0;
    m_numberSize = numberSize;
    m_speed = speed;
    for (int i=0; i<m_numberCnt; i++) {
        NumberScrollLabelBase* single = NumberScrollLabelBase::createLabel(numberSize,speed*pow(2,i));
        single->setPosition(Point(numberSize*(m_numberCnt-i-1),0));
        single->setTag(i);
        this->addChild(single);
    }
    return true;
}

void NumberScrollLabel::add(int step){
    for (int i=0; i<m_numberCnt; i++) {
        int tmp=step/pow(10, i);
        tmp = tmp % 10;
        if(tmp==0)
            continue;
        
        bool flag = false;//进位标志
        NumberScrollLabelBase* single = (NumberScrollLabelBase*)getChildByTag(i);
        int target = (*single).currentNumber+tmp;
        if(target>=10){
            //需要进位
            flag = true;
        }
        single->setNumber(target%10,0);
        for (int j=i+1; j<m_numberCnt; j++) {
            if (flag) {
                flag = false;
                //进位
                single = (NumberScrollLabelBase*)getChildByTag(j);
                target = (*single).currentNumber+1;
                if(target>=10){
                    //需要进位
                    flag = true;
                }
                single->setNumber(target%10,0);
            }else{
                //没有进位
                break;
            }
        }
    }
}

void NumberScrollLabel::addByOne(){
    bool flag = false;//进位标志
    NumberScrollLabelBase* single = (NumberScrollLabelBase*)getChildByTag(0);
    int tmp = (*single).currentNumber+1;
    if(tmp>=10){
        //需要进位
        flag = true;
    }
    single->setNumber(tmp%10);
    for (int i=1; i<m_numberCnt; i++) {
        if (flag) {
            flag = false;
            //进位
            single = (NumberScrollLabelBase*)getChildByTag(i);
            tmp = (*single).currentNumber+1;
            if(tmp>=10){
                //需要进位
                flag = true;
            }
            single->setNumber(tmp%10);
        }else{
            //没有进位
            break;
        }
    }
}

void NumberScrollLabel::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags){
    
    if (!isVisible()) {
        return;
    }
    _beforeVisitCmdScissor.init(_globalZOrder);
    _beforeVisitCmdScissor.func = CC_CALLBACK_0(NumberScrollLabel::onBeforeVisitScissor, this);
    renderer->addCommand(&_beforeVisitCmdScissor);
    
    Node::visit(renderer, parentTransform, parentFlags);
    
    _afterVisitCmdScissor.init(_globalZOrder);
    _afterVisitCmdScissor.func = CC_CALLBACK_0(NumberScrollLabel::onAfterVisitScissor, this);
    renderer->addCommand(&_afterVisitCmdScissor);
}

void NumberScrollLabel::onBeforeVisitScissor()
{
    Point pos = getPosition();
    pos = this->getParent()->convertToWorldSpace(pos);
    Rect rect = Rect(pos.x, pos.y, m_numberCnt*m_numberSize, m_numberSize);
    glEnable(GL_SCISSOR_TEST);
    Director::getInstance()->getOpenGLView()->setScissorInPoints(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}

void NumberScrollLabel::onAfterVisitScissor()
{
    glDisable(GL_SCISSOR_TEST);
}


