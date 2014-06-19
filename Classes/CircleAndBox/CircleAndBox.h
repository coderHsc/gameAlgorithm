/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:圆与矩阵碰撞
**************************************************/
#ifndef __CIRCLEANDBOX__
#define __CIRCLEANDBOX__
#include "headfile.h"
#include "MenuScene.h"

class CircleAndBox : public cocos2d::CCLayer
{
public:
	CircleAndBox();
	~CircleAndBox();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(CircleAndBox);
	void update(float dt);

	float DistanceBetweenTwoPoints(float x1, float y1, float x2, float y2);
	float DistanceFromPointToLine(float x, float y, float x1, float y1, float x2, float y2);
	bool  IsCircleIntersectRectangle(float x, float y, float r, float x0, float y0, float x1, float y1, float x2, float y2);
	void  menuBackCallback(CCObject* pSender);
private:
	NewCircle   m_Circle;
	NewRect     m_RectB;
	CCSize      m_winSize;
};

#endif