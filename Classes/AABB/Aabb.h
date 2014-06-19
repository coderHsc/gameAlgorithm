/*************************************************
 Copyright:hushencheng
 Author:hushencheng
 Date:2014-6-3
 Description:矩阵与矩阵碰撞算法
 **************************************************/

#ifndef __AABB__
#define __AABB__
#include "headfile.h"
#include "MenuScene.h"
class Aabb : public cocos2d::CCLayer
{
public:
	Aabb();
	~Aabb();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Aabb);
	void update(float dt);
    
	bool Algorithm_Aabb(float x1,float y1,float w1,float h1,float x2,float y2,float w2,float h2);
	void menuBackCallback(CCObject* pSender);
private:
	NewRect     m_RectA;
	NewRect     m_RectB;
	CCSize      m_winSize;
};

#endif