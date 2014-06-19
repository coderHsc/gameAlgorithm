/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-5-30
Description:宽度优先搜索
**************************************************/
#ifndef __BFS__
#define __BFS__
#include "headfile.h"
#include "MenuScene.h"

class Bfs : public cocos2d::CCLayer
{
public:
	Bfs();
	~Bfs();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Bfs);
	//bfs
	void algorithm_bfs(float dt);
	void  menuBackCallback(CCObject* pSender);
private:
	//tiledMap
	CCTMXTiledMap*       m_map;
	int**                m_arrayMap;
    
    
	CCSprite*            m_sprite[20][20];

	//判断是否访问
	bool				 m_vis[20][20];
	//队列
	std::queue<Node >    m_queue;
};

#endif