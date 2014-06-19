/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-3
Description:快速排序
**************************************************/
#include"Qsort.h"

Qsort::Qsort()
{
}
Qsort::~Qsort()
{
}
CCScene* Qsort::scene()
{
	CCScene* scene = CCScene::create();
	Qsort* layer = Qsort::create();
	scene->addChild(layer);
	return scene;
}
bool Qsort::init()
{
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

	//排序前
	int a[]={10,20,5,8,6,10,11,22,45,42};

	CCLOG("print no sort a[]:");
	for(int i=0;i<10;i++)
	{
		CCLOG("%d ",a[i]);
	}
	qsort(a,0,9);
	CCLOG("print qsort after a[]:");
	for(int i=0;i<10;i++)
	{
		CCLOG("%d ",a[i]);
	}

	return true;
}
void Qsort::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}
//快速排序
void Qsort::qsort( int num[],int shangbiao,int xiabiao )
{
	int i=shangbiao,j=xiabiao;  
	int key=i;  
	int t;  
	if(shangbiao<xiabiao)  
	{  
		while(i<j)  
		{  
			for(;j>key;j--)  
			{  
				if(num[j]<num[key])  
				{  
					t=num[j];  
					num[j]=num[key];  
					num[key]=t;  
					key=j;  
					break;  
				}  
			}  
			i++;  
			for(;i<key;i++)  
			{  
				if(num[i]>num[key])  
				{  
					t=num[i];  
					num[i]=num[key];  
					num[key]=t;  
					key=i;  
					break;  
				}  
			}  
			j--;  
		}  
		qsort(num,shangbiao,key-1);  
		qsort(num,key+1,xiabiao);  
	}  

}

