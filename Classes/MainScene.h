#pragma once

#include "cocos2d.h"
#include "ScreenShake.h"

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

	~MainScene();

    virtual bool init();
	
    CREATE_FUNC(MainScene);
	
private:
	cocos2d::TMXTiledMap * level;
	
	ScreenShake * shake;
};
