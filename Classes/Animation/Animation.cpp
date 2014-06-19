/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-4
Description:cocos2d-x帧动画算法
**************************************************/
#include"Animation.h"

Animation::Animation()
{
}
Animation::~Animation()
{
}
CCScene* Animation::scene()
{
	CCScene* scene = CCScene::create();
	Animation* layer = Animation::create();
	scene->addChild(layer);
	return scene;
}
bool Animation::init()
{
	//窗口大小
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

	
    
    //初始化   368*540
    
    CCAnimation* rightAnimation=CCAnimation::create();
	rightAnimation->setDelayPerUnit(0.2f);
	rightAnimation->addSpriteFrame(CCSpriteFrame::create("boss1.png",CCRectMake(0,0,92,108)));
	rightAnimation->addSpriteFrame(CCSpriteFrame::create("boss1.png",CCRectMake(92*1,0,92,108)));
	rightAnimation->addSpriteFrame(CCSpriteFrame::create("boss1.png",CCRectMake(92*2,0,92,108)));
	rightAnimation->addSpriteFrame(CCSpriteFrame::create("boss1.png",CCRectMake(92*3,0,92,108)));
	rightAnimation->setRestoreOriginalFrame(true);
	m_rightAnimate=  CCAnimate::create(rightAnimation);
	
    
    m_hero = CCSprite::create("boss1.png",CCRectMake(0, 0,92,108));
    m_hero->setPosition(ccp(winSize.width/2,winSize.height/2));
   
    //执行动作
    m_hero->runAction(CCRepeatForever::create(m_rightAnimate));
    this->addChild(m_hero);
	
	return true;
}


void Animation::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}


