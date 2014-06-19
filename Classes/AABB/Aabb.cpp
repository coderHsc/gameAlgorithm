/*************************************************
 Copyright:hushencheng
 Author:hushencheng
 Date:2014-6-3
 Description:矩阵与矩阵碰撞算法
 **************************************************/
#include"Aabb.h"
Aabb::Aabb()
{
}
Aabb::~Aabb()
{
}
CCScene* Aabb::scene()
{
	CCScene* scene = CCScene::create();
	Aabb* layer = Aabb::create();
	scene->addChild(layer);
	return scene;
}
bool Aabb::init()
{
	//获取屏幕宽高
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
                                                       menu_selector(Aabb::menuBackCallback));
	CCMenu* pMenuBack= CCMenu::create(backBtn, NULL);
    
	pMenuBack->setScaleX(m_winSize.width/pMenuBack->getContentSize().width*0.5);
	pMenuBack->setScaleY(m_winSize.height/pMenuBack->getContentSize().height*0.6);
	pMenuBack->setPosition(ccp(m_winSize.width*0.6,m_winSize.height*0.75));
	this->addChild(pMenuBack,2);
    
    
	CCLabelTTF* pLabelCircleAndBox = CCLabelTTF::create("backButton", "Arial", 18);
	pLabelCircleAndBox->setPosition(ccp(m_winSize.width *0.85, m_winSize.height*0.95));
	this->addChild(pLabelCircleAndBox, 2);
    
	//初始化两个矩阵
    
	m_RectA.back = CCSprite::create("red.png");
	m_RectA.x=m_winSize.width/2-32;
	m_RectA.y=0;
	m_RectA.h=64;
	m_RectA.w=64;
	m_RectA.step=10;
	m_RectA.dir=1;
	m_RectA.back->setAnchorPoint(ccp(0,0));
	m_RectA.back->setPosition(ccp(m_RectA.x,m_RectA.y));
	this->addChild(m_RectA.back);
    
    
	m_RectB.back = CCSprite::create("red.png");
	m_RectB.x=m_winSize.width/2-32;
	m_RectB.y=m_winSize.height-64;
	m_RectB.h=64;
	m_RectB.w=64;
	m_RectB.step=10;
	m_RectB.dir=1;
	m_RectB.back->setAnchorPoint(ccp(0,0));
	m_RectB.back->setPosition(ccp(m_RectB.x,m_RectB.y));
	this->addChild(m_RectB.back);
    
	srand((unsigned)time(NULL));
    
    
    
	this->scheduleUpdate();
	return true;
}

void Aabb::update( float dt )
{
	//让方块随机移动
	if(m_RectA.step>0)
	{
		m_RectA.step--;
		if(m_RectA.dir==1)
		{
			if(m_RectA.x+65<=m_winSize.width)
				m_RectA.x++;
			else
				m_RectA.step=0;
		}
		else if(m_RectA.dir==2)
		{
			if(m_RectA.x-1>=0)
				m_RectA.x--;
			else
				m_RectA.step=0;
		}
		else if(m_RectA.dir==3)
		{
			if(m_RectA.y+65<=m_winSize.height)
				m_RectA.y++;
			else
				m_RectA.step=0;
            
		}
		else if(m_RectA.dir==4)
		{
			if(m_RectA.y-1>=0)
				m_RectA.y--;
			else
				m_RectA.step=0;
		}
        
	}
	else
	{
		m_RectA.dir=rand()%4+1;
		m_RectA.step=10;
	}
	m_RectA.back->setPosition(ccp(m_RectA.x,m_RectA.y));
    
	m_RectB.y--;
    
	m_RectB.back->setPosition(ccp(m_RectB.x,m_RectB.y));
    
	if(Algorithm_Aabb(m_RectA.x,m_RectA.y,m_RectA.w,m_RectA.h,
					  m_RectB.x,m_RectB.y,m_RectB.w,m_RectB.h))
	{
		this->unscheduleUpdate();
	}
    
}

//x1 + w1 > x2 限定 第一个矩形的右边线在第二个矩形的左边线右边
//x1 < x2 + w2 限定 第一个矩形的左边线在第二个矩形的右边线左边
//同理，
//y1 + h1 > y2 限定 第一个矩形的下边线在第二个矩形的上边线下面
//y1 < y2 + h2 限定 第一个矩形的上边线在第二个矩形的下边线上边

bool Aabb::Algorithm_Aabb( float x1,float y1,float w1,float h1,float x2,float y2,float w2,float h2 )
{
	return  x1 + w1 > x2 && x1 < x2 + w2 && y1 + h1 > y2 && y1 < y2 + h2;
}

void Aabb::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}


