/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-4
Description:二分查找
**************************************************/
#ifndef __BINARYSEARCH__
#define __BINARYSEARCH__
#include "headfile.h"
#include "MenuScene.h"

class BinarySearch : public cocos2d::CCLayer
{
public:
	BinarySearch();
	~BinarySearch();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(BinarySearch);

	//binarysearch
    int  algorithm_BinarySearch(int arr[],int size,int target);
    
	void  menuBackCallback(CCObject* pSender);

private:

};

#endif