# Filters
滤镜效果  从网上搜集到的  改成了适用于Cocos2dx 3.2的版本  其中水纹效果还需要改正  而且效率很低  在iphone6的模拟器上基本跑不动

一些简单的灰度、颜色滤镜效果模拟器还是能带的动，如果只是想学习shader的话可以直接运行在mac上，这样就不用考虑性能问题。


项目里加入了工厂模式，使用方法很简单

1.添加自己的新滤镜

从Filter继承一个新类A，如下所示：
#include "Filter.h"

class A : public Filter
{
public:
    A();   
private:
    virtual void loadShader();
    virtual void bindAttributes();
    virtual void bindUniforms();
};
REGISTER_CLASS(Filter,FlashFilter);

2.使用自己的新滤镜

a.创建一个精灵
//获取屏幕大小
Size visibleSize = Director::getInstance()->getWinSize();
//创建精灵
auto hello = SpriteWithFilter::create("HelloWorld.png");
//设置精灵位置
hello->setPosition(Vec2(visibleSize.width/2 , visibleSize.height/2));

b.创建滤镜
Filter* filter = CREATE_CLASS(Filter, "A");

c.使用滤镜
hello->setFilter(filter);
//添加到Layer中显示    
addChild(hello);
//最后不要忘了使用CREATE_CLASS这个宏创建的对象是new出来的，需要释放掉，不然引用计数一致不会变为0    
filter->autorelease();

