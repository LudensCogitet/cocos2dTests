#include "MainScene.h"
#include "ScreenShake.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

MainScene::~MainScene() {
	delete this->shake;
	this->shake = nullptr;
}

bool MainScene::init()
{	
    if ( !Scene::init() ) {
        return false;
    }
    
    auto size = Director::getInstance()->getVisibleSize();

	this->level = TMXTiledMap::create("cave1.tmx");

	this->addChild(this->level);
	
	this->shake = new ScreenShake(3, 20);
	
	auto touchEventListener = EventListenerTouchOneByOne::create();
    
	touchEventListener->onTouchBegan = [=](Touch* touch, Event* event)->bool {
		this->shake->runOn(this->level);
		return true;
	};
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchEventListener, this);
	
    return true;
}