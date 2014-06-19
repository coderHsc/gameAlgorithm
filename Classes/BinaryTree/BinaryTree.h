/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-5
Description:二叉树
**************************************************/
#ifndef __BinaryTree__
#define __BinaryTree__
#include "headfile.h"
#include "MenuScene.h"

class BinaryTree : public cocos2d::CCLayer
{
public:
	BinaryTree();
	~BinaryTree();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(BinaryTree);

	//BinaryTree
    void build_tree(int arr[],int l,int r);
    
    void print_tree(int l,int r);
    //int find_tree(int num);
    
	void  menuBackCallback(CCObject* pSender);

private:
    
    int m_tree[100000];

};

#endif