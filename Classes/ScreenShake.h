#pragma once

#include "cocos2d.h"

class ScreenShake {
public:
	ScreenShake(float, float);
	~ScreenShake();
		
	void runOn(cocos2d::Node*);
		
private:
	cocos2d::Action* 	action;
};