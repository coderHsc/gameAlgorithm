/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-4
Description:cocos2d-x帧动画算法
**************************************************/
#ifndef __ANIMATION__
#define __ANIMATION__
#include "headfile.h"
#include "MenuScene.h"

class Animation : public cocos2d::CCLayer
{
public:
	Animation();
	~Animation();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Animation);

	//Animation
	void  menuBackCallback(CCObject* pSender);

private:
    CCAnimate*     m_rightAnimate;
    CCSprite*      m_hero;

};

#endif