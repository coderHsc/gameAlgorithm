/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-5-30
Description:深度优先搜索
**************************************************/
#include"Dfs.h"
Dfs::Dfs()
{
}
Dfs::~Dfs()
{
	int maxHeight = m_map->getMapSize().height;
	int maxWidth  = m_map->getMapSize().width;

	for (int i = 0; i < maxWidth; i++)
	{
		delete[] m_arrayMap[i];
		m_arrayMap[i] = NULL;
	}
}
CCScene* Dfs::scene()
{
	CCScene* scene = CCScene::create();
	Dfs* layer = Dfs::create();
	scene->addChild(layer);
	return scene;
}
bool Dfs::init()
{
	//winSize
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//back button
	CCMenuItemImage *backBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(Dfs::menuBackCallback));
	CCMenu* pMenuBack= CCMenu::create(backBtn, NULL);

	pMenuBack->setScaleX(winSize.width/pMenuBack->getContentSize().width*0.5);
	pMenuBack->setScaleY(winSize.height/pMenuBack->getContentSize().height*0.6);
	pMenuBack->setPosition(ccp(winSize.width*0.6,winSize.height*0.75));
	this->addChild(pMenuBack,2);


	CCLabelTTF* pLabelCircleAndBox = CCLabelTTF::create("backButton", "Arial", 18);
	pLabelCircleAndBox->setPosition(ccp(winSize.width *0.85, winSize.height*0.95));
	this->addChild(pLabelCircleAndBox, 2);


	//加载tiled地图
	m_map=CCTMXTiledMap::create("bfs.tmx");
	m_map->setScaleX(winSize.width/884);
	m_map->setScaleY(winSize.height/640);
	this->addChild(m_map);


	int maxHeight = m_map->getMapSize().height;
	int maxWidth  = m_map->getMapSize().width;

	//创建动态数组
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

	//宽度优先搜索初始化
	memset(m_vis,false,sizeof(m_vis));
	Node start;
	start.x=0;start.y=0; start.step=0;
	m_vis[0][0]=true;
	m_sprite[0][0]->setVisible(true);
		//this->schedule(schedule_selector(Dfs::algorithm_dfs), 0.5f);
    m_isFind=false;
    dfs(0,0);
    

	return true;
}

void Dfs::dfs(int x,int y)
{
    if(x==12&&y==9)
    {
        m_isFind=true;
        return ;
    }
    if(m_isFind) return ;
    //搜索方向
    int   dx[]={1,0,-1,0};
    int   dy[]={0,-1,0,1};
    
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        //判断是否越界
        if(nx<0||nx>=13||ny<0||ny>=10) continue;
        //判断是否为墙
        if(m_arrayMap[nx][ny]==1) continue;
        //判断是否访问
        if(!m_vis[nx][ny]&&!m_isFind)
        {
            m_vis[nx][ny]=true;
            m_sprite[nx][ny]->setVisible(true);
            dfs(nx,ny);
        }
    }

}

void Dfs::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}