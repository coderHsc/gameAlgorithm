/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:快速排序
**************************************************/
#ifndef __QSORT__
#define __QSORT__
#include "headfile.h"
#include "MenuScene.h"
class Qsort : public cocos2d::CCLayer
{
public:
	Qsort();
	~Qsort();
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Qsort);

	void qsort(int num[],int shangbiao,int xiabiao); 
	//Qsort
	void  menuBackCallback(CCObject* pSender);

private:

};

#endif