/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-5-30
Description:宽度优先搜索
**************************************************/
#include"Bfs.h"
Bfs::Bfs()
{
}
Bfs::~Bfs()
{
	int maxWidth  = m_map->getMapSize().width;
	for (int i = 0; i < maxWidth; i++)
	{
		delete[] m_arrayMap[i];
		m_arrayMap[i] = NULL;
	}
}
CCScene* Bfs::scene()
{
    CCScene* scene = CCScene::create();
    Bfs* layer     = Bfs::create();
	scene->addChild(layer);
	return scene;
}
bool Bfs::init()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//back button
	CCMenuItemImage *backBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(Bfs::menuBackCallback));
	CCMenu* pMenuBack= CCMenu::create(backBtn, NULL);

	pMenuBack->setScaleX(winSize.width/pMenuBack->getContentSize().width*0.5);
	pMenuBack->setScaleY(winSize.height/pMenuBack->getContentSize().height*0.6);
	pMenuBack->setPosition(ccp(winSize.width*0.6,winSize.height*0.75));
	this->addChild(pMenuBack,2);


	CCLabelTTF* pLabelCircleAndBox = CCLabelTTF::create("backButton", "Arial", 18);
	pLabelCircleAndBox->setPosition(ccp(winSize.width *0.85, winSize.height*0.95));
	this->addChild(pLabelCircleAndBox, 2);


	//加载地图
	m_map=CCTMXTiledMap::create("bfs.tmx");
	m_map->setScaleX(winSize.width/884);
	m_map->setScaleY(winSize.height/640);
	this->addChild(m_map);
	

	int maxHeight = m_map->getMapSize().height;
	int maxWidth  = m_map->getMapSize().width;

	//开辟动态数组
	m_arrayMap=new int *[maxWidth];
	for(int i=0;i<maxWidth;i++)
	{
		m_arrayMap[i] = new int[maxHeight];
	}
	for(int i=0;i<maxWidth;i++)
	{
		for(int j=0;j<maxHeight;j++)
		{
			m_arrayMap[i][j]=0;
		}
	}
	CCTMXLayer* layer=m_map->layerNamed("block");
	for(int i=0;i<maxWidth;i++)
	{
		for(int j=0;j<maxHeight;j++)
		{
			unsigned int m_gid=layer->tileGIDAt(ccp(i,j));
			//转换成opengl坐标
			if(m_gid>0)
			{
				m_arrayMap[i][maxHeight-j-1]=1;
			}
		}
	}
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<10;j++)
		{
			m_sprite[i][j]=CCSprite::create("red.png");
			m_sprite[i][j]->setScaleX((winSize.width/13)/m_sprite[i][j]->getContentSize().width);
			m_sprite[i][j]->setScaleY((winSize.height/10)/m_sprite[i][j]->getContentSize().height);
			m_sprite[i][j]->setPosition(ccp(i*winSize.width/13+(winSize.width/13)/2,j*winSize.height/10+winSize.height/10/2));
			m_sprite[i][j]->setVisible(false);
			this->addChild(m_sprite[i][j]);
		}
	}

	//宽度有限搜索初始化
	memset(m_vis,false,sizeof(m_vis));
	Node start;
	start.x=0;start.y=0; start.step=0;
	m_vis[0][0]=true;
	m_sprite[0][0]->setVisible(true);
	m_queue.push(start);
	this->schedule(schedule_selector(Bfs::algorithm_bfs), 0.5f);
	
	return true;
}

//宽端有限搜索
void Bfs::algorithm_bfs( float dt )
{
	if(!m_queue.empty())
	{
		//四个方向
		int   dx[]={0,0,-1,1};
		int   dy[]={1,-1,0,0};
		Node now = m_queue.front(); m_queue.pop();
		if(now.x==4&&now.y==4)
		{
			CCLog("find!");
			this->unschedule(schedule_selector(Bfs::algorithm_bfs));
		}
        //搜索的四个方向
		for(int i=0;i<4;i++)
		{
			Node next = now;
			next.x = now.x+dx[i];
			next.y = now.y+dy[i];
			//判断越界没有
			if(next.x<0||next.x>=13||next.y<0||next.y>=10) continue;
			//判断是不是墙
			if(m_arrayMap[next.x][next.y]==1) continue;

			if(!m_vis[next.x][next.y])
			{
				m_vis[next.x][next.y]=true;
				m_sprite[next.x][next.y]->setVisible(true);
				m_queue.push(next);
			}
		}

	}
}


void Bfs::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}