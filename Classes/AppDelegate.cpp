#include "AppDelegate.h"
#include "MainScene.h"



USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(768, 1024);

AppDelegate::AppDelegate(){
}

AppDelegate::~AppDelegate() {
}


bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	
	if(!glview) {
        glview = GLViewImpl::create("Game");
        glview->setFrameSize(768, 1024);
        director->setOpenGLView(glview);
    }
    
    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);

    // create a scene. it's an autorelease object
    auto scene = MainScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {}
void AppDelegate::applicationWillEnterForeground() {}