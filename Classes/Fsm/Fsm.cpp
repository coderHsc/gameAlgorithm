/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:有限状态机
**************************************************/
#include"Fsm.h"

Fsm::Fsm()
{
}
Fsm::~Fsm()
{
}
CCScene* Fsm::scene()
{
	CCScene* scene = CCScene::create();
	Fsm* layer = Fsm::create();
	scene->addChild(layer);
	return scene;
}
bool Fsm::init()
{
	//winsize
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	
	//back button
	CCMenuItemImage *backBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(Fsm::menuBackCallback));
	CCMenu* pMenuBack= CCMenu::create(backBtn, NULL);

	pMenuBack->setScaleX(winSize.width/pMenuBack->getContentSize().width*0.5);
	pMenuBack->setScaleY(winSize.height/pMenuBack->getContentSize().height*0.6);
	pMenuBack->setPosition(ccp(winSize.width*0.6,winSize.height*0.75));
	this->addChild(pMenuBack,2);


	CCLabelTTF* pLabelCircleAndBox = CCLabelTTF::create("backButton", "Arial", 18);
	pLabelCircleAndBox->setPosition(ccp(winSize.width *0.85, winSize.height*0.95));
	this->addChild(pLabelCircleAndBox, 2);

	
	//setCurState
	m_CurState = State_FindBox;


	this->schedule(schedule_selector(Fsm::algorithm_Fsm), 1.0f);
	//this->scheduleUpdate();

	return true;
}

void Fsm::algorithm_Fsm( float dt )
{
	switch(m_CurState)
	{
	case State_IsRun:
		{
			CCLOG("State_IsRun");

			if(m_preState==State_FindBox)
			{
				m_CurState = State_HideBubble;
			}
			else if(m_preState==State_HideBubble)
			{
				m_CurState = State_FindBox;
			}
			
		}
		break;
	case State_FindBox:
		{
			CCLOG("State_FindBox");
			m_preState = m_CurState;

			m_CurState = State_IsRun;
		}
		break;
	case State_HideBubble:
		{
			CCLOG("State_HideBubble");

			m_preState = m_CurState;

			m_CurState = State_IsRun;
		}
		break;

	}
}

void Fsm::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}

