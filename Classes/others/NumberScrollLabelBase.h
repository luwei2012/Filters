//
//  NumberScrollLabelBase.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-6.
//
//

#ifndef __MyPlane__NumberScrollLabelBase__
#define __MyPlane__NumberScrollLabelBase__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class NumberScrollLabelBase : public Node{
    
public:
    int m_numberSize;
    int currentNumber;
    float m_speed;
    Node* m_visibleNode;
    Vector<Label*> labels;
    static NumberScrollLabelBase* createLabel(int numberSize=30,float speed = 1.0);
    bool init(int numberSize=30,float speed = 1.0);
    void setNumber(int var,float speed=-1.0);
    ~NumberScrollLabelBase();
};

#endif /* defined(__MyPlane__NumberScrollLabelBase__) */
