#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;

AppDelegate::AppDelegate() {
    
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        if(CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
        {
            //是 mac平台
            glview->setFrameSize(designResolutionSize.width, designResolutionSize.height);//设置窗口大小
        }
        
        director->setOpenGLView(glview);
    }
 
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_WIDTH);
    
    Size frameSize = glview->getFrameSize();
    
    std::vector<std::string> searchPath;
    
    if(frameSize.height>mediumResource.size.height){
        searchPath.push_back(largeResource.directory);
        director->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height,largeResource.size.width/designResolutionSize.width));
    }else if (frameSize.height > smallResource.size.height)    {
        searchPath.push_back(mediumResource.directory);
        
        director->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }    else    {
        searchPath.push_back(smallResource.directory);
        
        director->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }
    
    searchPath.push_back("music");
    searchPath.push_back("shader");
    
    FileUtils::getInstance()->setSearchPaths(searchPath);
    
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();
    
    // run
    director->runWithScene(scene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
