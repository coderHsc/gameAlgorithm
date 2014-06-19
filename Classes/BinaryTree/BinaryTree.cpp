/*************************************************
Copyright:hushencheng
Author:hushencheng
Date:2014-6-5
Description:二叉树
**************************************************/
#include"BinaryTree.h"

BinaryTree::BinaryTree()
{
}
BinaryTree::~BinaryTree()
{
}
CCScene* BinaryTree::scene()
{
    CCScene* scene    = CCScene::create();
    BinaryTree* layer = BinaryTree::create();
	scene->addChild(layer);
	return scene;
}
bool BinaryTree::init()
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
	int a[]={0,1,2,5,8,9,10,11,22,45,49};
    
    build_tree(a,1,10);
    print_tree(1,10);
    

	//qsort(a,0,9);
   // int position=algorithm_BinaryTree(a,10,9);
    
    //CCLOG("%d",position);
	
	return true;
}
void BinaryTree::build_tree(int arr[],int l,int r)
{
    if(l==r)
    {
        m_tree[l]=arr[l];
        return ;
    }
    int m=(l+r)>>1;
    build_tree(arr, l,m);
    build_tree(arr, m+1,r);
}
void BinaryTree::print_tree(int l, int r)
{
    if(l==r)
    {
        CCLOG("%d",m_tree[l]);
        return ;
    }
    
    int m=(l+r)>>1;
    print_tree(l,m);
    print_tree(m+1,r);
}



void BinaryTree::menuBackCallback( CCObject* pSender )
{
	CCScene* menuScene = MenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(menuScene);
}


