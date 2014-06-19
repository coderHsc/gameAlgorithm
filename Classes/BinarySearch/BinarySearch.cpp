/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-4
Description:二分查找
**************************************************/
#include"BinarySearch.h"

BinarySearch::BinarySearch()
{
}
BinarySearch::~BinarySearch()
{
}
CCScene* BinarySearch::scene()
{
	CCScene* scene = CCScene::create();
	BinarySearch* layer = BinarySearch::create();
	scene->addChild(layer);
	return scene;
}
bool BinarySearch::init()
{
	//ªÒ»°∆¡ƒªøÌ∏ﬂ
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//back button
	CCMenuItemImage *backBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(Fsm::menuBackCallback));
	CCMenu* pMenuBack= CCMenu::create(backBtn, NULL);

	pMenuBack->setScaleX(winSize.width/pMenuBack->getContentSize().width*0.5);
	pMenuBack->setScaleY(winSize.height/pMenuBack->getContentSize().height*0.6);
	pMenuBack->setPosition(ccp(winSize.width*0.6,winSize.height*0.75));
	this->addChild(pMenuBack,2);


	CCLabelTTF* pLabelCircleAndBox = CCLabelTTF::create("backButton", "Arial", 18);
	pLabelCircleAndBox->setPosition(ccp(winSize.width *0.85, winSize.height*0.95));
	this->addChild(pLabelCircleAndBox, 2);

	

	//≈≈–Ú≥ı ºªØ
	int a[]={1,2,5,8,9,10,11,22,45,49};

	//qsort(a,0,9);
    int position=algorithm_BinarySearch(a,10,9);
    
    CCLOG("%d",position);
	
	return true;
}


void BinarySearch::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}

int BinarySearch::algorithm_BinarySearch(int arr[],int size,int target)
{
    int position;
    int data;
    int bottom = 0, top = size - 1;
    while (bottom < top)
    {
        int mid = (bottom + top) / 2;
        data = arr[mid];
        if (data < target)
            bottom = mid + 1;
        else
            top = mid;
    }
    if (top < bottom) return -1;
    else {
        position = bottom;
        data = arr[bottom];
        if (data == target)  return position;
        else return -1;
    }
}

