/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:a*算法
**************************************************/

#include"Astar.h"
Astar::Astar()
{
}
Astar::~Astar()
{
	int maxWidth  = m_map->getMapSize().width;

	for (int i = 0; i < maxWidth; i++)
	{
		delete[] m_arrayMap[i];
		m_arrayMap[i] = NULL;
	}
}
CCScene* Astar::scene()
{
    CCScene* scene = CCScene::create();
    Astar* layer   = Astar::create();
	scene->addChild(layer);
	return scene;
}
bool Astar::init()
{
	//winsize
    CCSize winSize           = CCDirector::sharedDirector()->getWinSize();

	//back button
    CCMenuItemImage *backBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(Astar::menuBackCallback));
    CCMenu* pMenuBack        = CCMenu::create(backBtn, NULL);

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

	//初始化a*算法
	memset(m_vis,false,sizeof(m_vis));
	Point start;
	start.x=0;start.y=0;
	start.G = 0;
	start.H = (12-0)*10+(9-0)*14;
	start.F = start.G + start.H;
	m_OpenList.push_back(start);

	this->schedule(schedule_selector(Astar::algorithm_Astar), 0.5f);

	return true;
}

//a*搜索
void Astar::algorithm_Astar( float dt )
{
	if(m_OpenList.size()!=0)
	{
		//1、寻找开启列表中F值最低的格子, 我们称它为当前格
		m_it = m_OpenList.begin();
		Point tempPoint;
		tempPoint.F = MAXVAL; 

		while(m_it!=m_OpenList.end())
		{
			if((*m_it).F<tempPoint.F)
			{
				tempPoint = (*m_it);
				m_eraseIt = m_it;
			}
			m_it++;
		}
        
        //2、把当前f值最低的格子切换到"关闭列表";
		m_CloseList.push_back(tempPoint);
        //3、从"开启列表"中删除当前f值最低的格子
		m_OpenList.erase(m_eraseIt);
        m_vis[ tempPoint.x ] [ tempPoint.y ]=true;
		m_sprite[tempPoint.x][tempPoint.y]->setVisible(true);
        
		//搜索方向
		int   dx[]={0,0,-1,1,1,1,-1,-1};
		int   dy[]={1,-1,0,0,1,-1,1,-1};
		//int dx[]={0,0,-1,1};
		//int dy[]={1,-1,0,0};


		//4、检查它所有相邻并且可以到达 (障碍物和 "关闭列表" 的方格都不考虑) 的方格.
        //如果这些方格还不在 "开启列表" 里的话, 将它们加入 "开启列表",
        //计算这些方格的 G, H 和 F 值各是多少, 并设置它们的 "父方格" 为 C.
		Point now = tempPoint;

		for(int i=0;i<8;i++)
		{
			Point next=now;
			next.x = now.x+dx[i];
			next.y = now.y+dy[i];

			next.px = now.x;
			next.py = now.y;
            //如果是上下左右 g值设为10,其他斜方形g值设为14。
			if(i<4)
				next.G = now.G+10;
			else
				next.G = now.G+14;
            
			next.H = (12-next.x)*10+(9-next.y)*14;
			next.F = next.G+next.H;

			//判断是否越界
			if(next.x<0||next.x>=13||next.y<0||next.y>=10) continue;
			//判断是否为墙
			if(m_arrayMap[next.x][next.y]==1) continue;
			//是否在关闭列表中
			if(m_vis[next.x][next.y])  continue;
            
        
            //如果当前搜索得到当节点a已经在开启列表中，说明之前的搜索已经产生了一条到达a点的路径。
            //那么我们需要看当前得到a点路径的g值 是否小于之前得到的路径的g值.
            //如果小的话，需要更改到达a点的路径（即将之前的路径从“开启列表”中移除，添加当前搜索得到的路径）
            
			bool isInOpenList = false;
			m_it=m_OpenList.begin();
			while(m_it!=m_OpenList.end())
			{
				if( (*m_it).x==next.x&& (*m_it).y==next.y )
				{
					isInOpenList=true;
					if(  (*m_it).G> next.G  )
					{
						m_OpenList.erase(m_it);
						m_OpenList.push_back(next);
						break;
					}
				}
				m_it++;
			}

			if(!isInOpenList)
			{
				m_OpenList.push_back(next);
			}
		}

		//判断终点是否已经在“开启列表”中了。
		m_it=m_OpenList.begin();
		while(m_it!=m_OpenList.end())
		{
			if( (*m_it).x==12&&(*m_it).y==9)
			{
				m_sprite[12][9]->setVisible(true);
				this->unschedule(schedule_selector(Astar::algorithm_Astar));
				break;
			}
			m_it++;
		}
	}
}

void Astar::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}