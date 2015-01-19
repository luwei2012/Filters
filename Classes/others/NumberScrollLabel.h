//
//  NumberScrollLabel.h
//  MyPlane
//
//  Created by 陆伟 on 15-1-6.
//
//

#ifndef __MyPlane__NumberScrollLabel__
#define __MyPlane__NumberScrollLabel__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class NumberScrollLabel : public Node{
    
public:
    CustomCommand _beforeVisitCmdScissor;
    CustomCommand _afterVisitCmdScissor;
    int m_numberCnt;
    int m_number;
    int m_numberSize;
    float m_speed;
    static NumberScrollLabel* createLabel(int numberCnt=3,int numberSize=30,float speed = 1.0);
    bool init(int numberCnt=3, int numberSize=30,float speed = 1.0);
    void add(int step);
    void addByOne();
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    
    void  onBeforeVisitScissor();
    void  onAfterVisitScissor();
};

#endif /* defined(__MyPlane__NumberScrollLabel__) */
