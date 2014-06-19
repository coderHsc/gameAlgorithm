/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:有限状态机
**************************************************/
#ifndef __FSM__
#define __FSM__
#include "headfile.h"
#include "MenuScene.h"
class Fsm : public cocos2d::CCLayer
{
public:
	Fsm();
	~Fsm();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Fsm);

	//fsm
	void algorithm_Fsm(float dt);
	void  menuBackCallback(CCObject* pSender);

private:
	int m_CurState;
	int m_preState;
};

#endif