/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:a*算法
**************************************************/
#ifndef __ASTAR__
#define __ASTAR__
#include "headfile.h"
#include "MenuScene.h"
class Astar : public cocos2d::CCLayer
{
public:
	Astar();
	~Astar();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Astar);
	//A*搜索
	void algorithm_Astar(float dt);
	void  menuBackCallback(CCObject* pSender);
private:
	CCTMXTiledMap*       m_map;
	int**                m_arrayMap;
	CCSprite*            m_sprite[20][20];

	
	//开启链表和关闭链表
	std::list<Point >	 m_CloseList;
	std::list<Point >	 m_OpenList;
	std::list<Point >::iterator m_it,m_eraseIt;
    //
	bool                 m_vis[20][20];


};

#endif