#ifndef __MENUSCENE__
#define __MENUSCENE__
#include "cocos2d.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Astar.h"
#include "Fsm.h"
#include "Aabb.h"
#include "CircleAndBox.h"
#include "Qsort.h"
#include "BinarySearch.h"
#include "Animation.h"
#include "BinaryTree.h"

using namespace cocos2d;


class MenuScene :public CCLayer
{
public:
	virtual bool init();
	CREATE_FUNC(MenuScene);
	static CCScene* scene();
	void menuBFSCallback(CCObject* pSender);
	void menuDFSCallback(CCObject* pSender);
	void menuAStarCallback(CCObject* pSender);
	void menuFsmCallback(CCObject* pSender);
	void menuAabbCallback(CCObject* pSender);
	void menuCircleAndBoxCallback(CCObject* pSender);
	void menuQsortCallback(CCObject* pSender);
    void menuBinarySearchCallback(CCObject* pSender);
    void menuAnimationCallback(CCObject* pSender);
    void menuBinaryTreeCallback(CCObject* pSender);
};
#endif