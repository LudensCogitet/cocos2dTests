#include "ScreenShake.h"

#include "cocos2d.h"

USING_NS_CC;

ScreenShake::ScreenShake(float shakeTime, float shakeMove){	
	Vector<FiniteTimeAction*> actionList;

	actionList.pushBack(MoveBy::create(shakeTime, Vec2(shakeMove,shakeMove)));
	actionList.pushBack(MoveBy::create(shakeTime, Vec2(-shakeMove,-shakeMove)));
	actionList.pushBack(MoveBy::create(shakeTime, Vec2(shakeMove,-shakeMove)));
	actionList.pushBack(MoveBy::create(shakeTime, Vec2(-shakeMove,shakeMove)));
	actionList.pushBack(MoveBy::create(shakeTime, Vec2(-shakeMove,-shakeMove)));
	actionList.pushBack(MoveBy::create(shakeTime, Vec2(shakeMove,shakeMove)));
	
	this->action = Sequence::create(actionList);
	this->action->retain();
}

ScreenShake::~ScreenShake(){
	this->action->release();
}

void ScreenShake::runOn(Node* subject) {
	subject->runAction(this->action);
}