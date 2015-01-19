//
//  Player.h
//  MyStudy
//
//  Created by 陆伟 on 14-12-25.
//
//

#ifndef __MyStudy__Player__
#define __MyStudy__Player__

#include "cocos2d.h"
#include <sstream>
using namespace std;
USING_NS_CC;

template<typename T>
string Conver2String(const T &value)
{
    stringstream ss;
    ss<<value;
    return ss.str();
}

class Player: public Sprite
{
public:
    static Player *createPlayer(const char* fileName);
    void downHp();//掉血
    void addScore(float _value);//加分
    void addKillCount(float _value);//加杀敌数
    bool isDead;//是否死亡
    
    
    int strongTime;//无敌时间
    bool isStrong; //是否处于无敌时间
    int strongCount;//无敌时的计数器
    void strongIng(float dt);//处理无敌时的闪烁
    int hp;//血量
    int hpMax;//血量最大值
    int score;//分数
    int killCount;//杀敌数   
    
    void playerInit();
};


#endif /* defined(__MyStudy__Player__) */
