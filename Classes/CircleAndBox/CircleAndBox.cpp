/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:圆与矩阵碰撞
**************************************************/
#include"CircleAndBox.h"
CircleAndBox::CircleAndBox()
{
}
CircleAndBox::~CircleAndBox()
{
}
CCScene* CircleAndBox::scene()
{
	CCScene* scene = CCScene::create();
	CircleAndBox* layer = CircleAndBox::create();
	scene->addChild(layer);
	return scene;
}
bool CircleAndBox::init()
{
	m_winSize = CCDirector::sharedDirector()->getWinSize();

	//背景
	CCSprite* bg = CCSprite::create("HelloWorld.png");
	bg->setScaleX(m_winSize.width/bg->getContentSize().width);
	bg->setScaleY(m_winSize.height/bg->getContentSize().height);
	bg->setPosition(ccp(m_winSize.width/2,m_winSize.height/2));
	this->addChild(bg);

	//back button
	CCMenuItemImage *backBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(CircleAndBox::menuBackCallback));
	CCMenu* pMenuBack= CCMenu::create(backBtn, NULL);

	pMenuBack->setScaleX(m_winSize.width/pMenuBack->getContentSize().width*0.5);
	pMenuBack->setScaleY(m_winSize.height/pMenuBack->getContentSize().height*0.6);
	pMenuBack->setPosition(ccp(m_winSize.width*0.6,m_winSize.height*0.75));
	this->addChild(pMenuBack,2);


	CCLabelTTF* pLabelCircleAndBox = CCLabelTTF::create("backButton", "Arial", 18);
	pLabelCircleAndBox->setPosition(ccp(m_winSize.width *0.85, m_winSize.height*0.95));
	this->addChild(pLabelCircleAndBox, 2);

	//创建一个圆
	m_Circle.back = CCSprite::create("circle.png");
	m_Circle.x=m_winSize.width/2;
	m_Circle.y=32;
	m_Circle.r=32;
	//m_RectA.back->setAnchorPoint(ccp(0,0));
	m_Circle.back->setPosition(ccp(m_Circle.x,m_Circle.y));
	this->addChild(m_Circle.back);

    //创建矩阵
	m_RectB.back = CCSprite::create("red.png");
	m_RectB.x=m_winSize.width/2-32;
	m_RectB.y=m_winSize.height-64;
	m_RectB.h=64.0f;
	m_RectB.w=64.0f;
	m_RectB.step=10;
	m_RectB.dir=1;
	m_RectB.back->setAnchorPoint(ccp(0,0));
	m_RectB.back->setPosition(ccp(m_RectB.x,m_RectB.y));
	this->addChild(m_RectB.back);

	srand((unsigned)time(NULL));

	this->scheduleUpdate();
	return true;
}

void CircleAndBox::update( float dt )
{
	//move Circle
	if(m_Circle.step>0)
	{
		m_Circle.step--;
		if(m_Circle.dir==1)
		{
			if(m_Circle.x+35<=m_winSize.width)
				m_Circle.x++;
			else
				m_Circle.step=0;
		}
		else if(m_Circle.dir==2)
		{
			if(m_Circle.x-35>=0)
				m_Circle.x--;
			else
				m_Circle.step=0;
		}
		else if(m_Circle.dir==3)
		{
			if(m_Circle.y+35<=m_winSize.height)
				m_Circle.y++;
			else
				m_Circle.step=0;

		}
		else if(m_Circle.dir==4)
		{
			if(m_Circle.y-35>=0)
				m_Circle.y--;
			else
				m_Circle.step=0;
		}

	}
	else
	{
		m_Circle.dir=rand()%4+1;
		m_Circle.step=10;
	}


	m_Circle.back->setPosition(ccp(m_Circle.x,m_Circle.y));

	m_RectB.y--;

	m_RectB.back->setPosition(ccp(m_RectB.x,m_RectB.y));

    
    //判断圆与矩阵是否相交

	if(IsCircleIntersectRectangle(m_Circle.x, m_Circle.y, m_Circle.r, 
    m_RectB.x+32,m_RectB.y+32,m_RectB.x+32,m_RectB.y+64,m_RectB.x+64,m_RectB.y+32))
	{
		this->unscheduleUpdate();
	}

}
// 计算两点之间的距离
float CircleAndBox::DistanceBetweenTwoPoints(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
//点到直线到距离
//设直线 L 的方程为Ax+By+C=0，点 P 的坐标为（Xo，Yo），则点 P 到直线 L 的距离为：
//d=│AXo+BYo+C│ / √（A²+B²）。
float CircleAndBox::DistanceFromPointToLine(float x, float y, float x1, float y1, float x2, float y2)
{
	float a = y2 - y1;
	float b = x1 - x2;
	float c = x2 * y1 - x1 * y2;
	assert(fabs(a) > 0.00001f || fabs(b) > 0.00001f);
	return fabs(a * x + b * y + c) / sqrt(a * a + b * b);
}
// 圆与矩形碰撞检测
// 圆心(x, y), 半径r, 矩形中心(x0, y0), 矩形上边中心(x1, y1), 矩形右边中心(x2, y2)
bool CircleAndBox::IsCircleIntersectRectangle(float x, float y, float r, float x0, float y0, float x1, float y1, float x2, float y2)
{
	float w1 = DistanceBetweenTwoPoints(x0, y0, x2, y2);
	float h1 = DistanceBetweenTwoPoints(x0, y0, x1, y1);
	float w2 = DistanceFromPointToLine(x, y, x0, y0, x1, y1);
	float h2 = DistanceFromPointToLine(x, y, x0, y0, x2, y2);
	if (w2 > w1 + r)
		return false;
	if (h2 > h1 + r)
		return false;
	if (w2 <= w1)
		return true;
	if (h2 <= h1)
		return true;
	return (w2 - w1) * (w2 - w1) + (h2 - h1) * (h2 - h1) <= r * r;
}

void CircleAndBox::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}

