/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-5-30
Description:深度优先搜索
**************************************************/
#ifndef __DFS__
#define __DFS__

#include "headfile.h"
#include "MenuScene.h"

using namespace cocos2d;

class Dfs : public cocos2d::CCLayer
{
public:
	Dfs();
	~Dfs();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Dfs);


	//深度优先搜索
    void dfs(int x,int y);
    
	void  menuBackCallback(CCObject* pSender);
private:
	CCTMXTiledMap*       m_map;
	int**                m_arrayMap;
	CCSprite*            m_sprite[20][20];
	//判断是否访问
	bool				 m_vis[20][20];
    
    bool                 m_isFind;

};

#endif