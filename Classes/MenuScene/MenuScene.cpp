#include "MenuScene.h"


CCScene* MenuScene::scene()
{
	CCScene* scene = CCScene::create();
	MenuScene* layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	
	CCSprite* bg = CCSprite::create("game_bg.png");
	bg->setScaleX(winSize.width/bg->getContentSize().width);


	bg->setScaleY(winSize.height/bg->getContentSize().height);
	bg->setPosition(ccp(winSize.width/2,winSize.height/2));
	this->addChild(bg);

	//Bfs
	CCMenuItemImage *bfsBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(MenuScene::menuBFSCallback));
	CCMenu* pMenubfs = CCMenu::create(bfsBtn, NULL);
	pMenubfs->setScaleX(winSize.width/pMenubfs->getContentSize().width*0.5);
	pMenubfs->setScaleY(winSize.height/pMenubfs->getContentSize().height*0.6);
	pMenubfs->setPosition(ccp(winSize.width/2*0.25,winSize.height*0.7));

	this->addChild(pMenubfs,2);

	CCLabelTTF* pLabelbfs = CCLabelTTF::create("Bfs", "Arial", 24);
	pLabelbfs->setPosition(ccp(winSize.width / 2*0.75, winSize.height*0.9));
	this->addChild(pLabelbfs, 2);

	//Dfs
	CCMenuItemImage *dfsBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(MenuScene::menuDFSCallback));
	CCMenu* pMenudfs = CCMenu::create(dfsBtn, NULL);
	pMenudfs->setScaleX(winSize.width/pMenudfs->getContentSize().width*0.5);
	pMenudfs->setScaleY(winSize.height/pMenudfs->getContentSize().height*0.6);
	pMenudfs->setPosition(ccp(winSize.width/2*0.25,winSize.height*0.6));
	this->addChild(pMenudfs,2);

	CCLabelTTF* pLabeldfs = CCLabelTTF::create("Dfs", "Arial", 24);
	pLabeldfs->setPosition(ccp(winSize.width / 2*0.75, winSize.height*0.8));
	this->addChild(pLabeldfs, 2);

	//Astar
	CCMenuItemImage *AstarBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(MenuScene::menuAStarCallback));
	CCMenu* pMenuAstar = CCMenu::create(AstarBtn, NULL);

	pMenuAstar->setScaleX(winSize.width/pMenuAstar->getContentSize().width*0.5);
	pMenuAstar->setScaleY(winSize.height/pMenuAstar->getContentSize().height*0.6);
	pMenuAstar->setPosition(ccp(winSize.width/2*0.25,winSize.height*0.5));
	this->addChild(pMenuAstar,2);

	CCLabelTTF* pLabelAstar = CCLabelTTF::create("Astar", "Arial", 24);
	pLabelAstar->setPosition(ccp(winSize.width / 2*0.75, winSize.height*0.7));
	this->addChild(pLabelAstar, 2);


	//fsm
	CCMenuItemImage *FsmBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(MenuScene::menuFsmCallback));
	CCMenu* pMenuFsm= CCMenu::create(FsmBtn, NULL);

	pMenuFsm->setScaleX(winSize.width/pMenuFsm->getContentSize().width*0.5);
	pMenuFsm->setScaleY(winSize.height/pMenuFsm->getContentSize().height*0.6);
	pMenuFsm->setPosition(ccp(winSize.width/2*0.25,winSize.height*0.4));
	this->addChild(pMenuFsm,2);

	CCLabelTTF* pLabelFsm = CCLabelTTF::create("Fsm", "Arial", 24);
	pLabelFsm->setPosition(ccp(winSize.width / 2*0.75, winSize.height*0.6));
	this->addChild(pLabelFsm, 2);



	//aabb
	CCMenuItemImage *aabbBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(MenuScene::menuAabbCallback));
	CCMenu* pMenuAabb= CCMenu::create(aabbBtn, NULL);

	pMenuAabb->setScaleX(winSize.width/pMenuAabb->getContentSize().width*0.5);
	pMenuAabb->setScaleY(winSize.height/pMenuAabb->getContentSize().height*0.6);
	pMenuAabb->setPosition(ccp(winSize.width/2*0.25,winSize.height*0.3));
	this->addChild(pMenuAabb,2);

	CCLabelTTF* pLabelAabb = CCLabelTTF::create("Aabb", "Arial", 24);
	pLabelAabb->setPosition(ccp(winSize.width / 2*0.75, winSize.height*0.5));
	this->addChild(pLabelAabb, 2);

	//CircleAndBox
	CCMenuItemImage *CircleAndBoxBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(MenuScene::menuCircleAndBoxCallback));
	CCMenu* pMenuCircleAndBox= CCMenu::create(CircleAndBoxBtn, NULL);

	pMenuCircleAndBox->setScaleX(winSize.width/pMenuCircleAndBox->getContentSize().width*0.5);
	pMenuCircleAndBox->setScaleY(winSize.height/pMenuCircleAndBox->getContentSize().height*0.6);
	pMenuCircleAndBox->setPosition(ccp(winSize.width/2*0.25,winSize.height*0.2));
	this->addChild(pMenuCircleAndBox,2);

	CCLabelTTF* pLabelCircleAndBox = CCLabelTTF::create("CircleAndBox", "Arial", 18);
	pLabelCircleAndBox->setPosition(ccp(winSize.width / 2*0.75, winSize.height*0.4));
	this->addChild(pLabelCircleAndBox, 2);

	//Qsort
	CCMenuItemImage *QsortBtn = CCMenuItemImage::create(
		"startbtn_normal.png",
		"startbtn_touched.png",
		this,
		menu_selector(MenuScene::menuQsortCallback));
	CCMenu* pMenuQsort= CCMenu::create(QsortBtn, NULL);

	pMenuQsort->setScaleX(winSize.width/pMenuQsort->getContentSize().width*0.5);
	pMenuQsort->setScaleY(winSize.height/pMenuQsort->getContentSize().height*0.6);
	pMenuQsort->setPosition(ccp(winSize.width/2*0.25,winSize.height*0.1));
	this->addChild(pMenuQsort,2);

	CCLabelTTF* pLabelQsort = CCLabelTTF::create("Qsort", "Arial", 24);
	pLabelQsort->setPosition(ccp(winSize.width / 2*0.75, winSize.height*0.3));
	this->addChild(pLabelQsort, 2);
    
    
    
    //BinarySearch
	CCMenuItemImage *BinarySearchBtn = CCMenuItemImage::create(
                                                        "startbtn_normal.png",
                                                        "startbtn_touched.png",
                                                        this,
                                                        menu_selector(MenuScene::menuBinarySearchCallback));
	CCMenu* pMenuBinarySearch= CCMenu::create(BinarySearchBtn, NULL);
    
	pMenuBinarySearch->setScaleX(winSize.width/pMenuBinarySearch->getContentSize().width*0.5);
	pMenuBinarySearch->setScaleY(winSize.height/pMenuBinarySearch->getContentSize().height*0.6);
	pMenuBinarySearch->setPosition(ccp(winSize.width/2*0.9,winSize.height*0.7));
	this->addChild(pMenuBinarySearch,2);
    
	CCLabelTTF* pLabelBinarySearch = CCLabelTTF::create("BinarySearch", "Arial", 18);
	pLabelBinarySearch->setPosition(ccp(winSize.width *0.7, winSize.height*0.9));
	this->addChild(pLabelBinarySearch, 2);
    
    //Animation
	CCMenuItemImage *AnimationBtn = CCMenuItemImage::create(
                                                               "startbtn_normal.png",
                                                               "startbtn_touched.png",
                                                               this,
                                                               menu_selector(MenuScene::menuAnimationCallback));
	CCMenu* pMenuAnimation= CCMenu::create(AnimationBtn, NULL);
    
	pMenuAnimation->setScaleX(winSize.width/pMenuAnimation->getContentSize().width*0.5);
	pMenuAnimation->setScaleY(winSize.height/pMenuAnimation->getContentSize().height*0.6);
	pMenuAnimation->setPosition(ccp(winSize.width/2*0.9,winSize.height*0.6));
	this->addChild(pMenuAnimation,2);
    
	CCLabelTTF* pLabelAnimation = CCLabelTTF::create("Animation", "Arial", 18);
	pLabelAnimation->setPosition(ccp(winSize.width *0.7, winSize.height*0.8));
	this->addChild(pLabelAnimation, 2);
    
    
    //BinaryTree
	CCMenuItemImage *BinaryTreeBtn = CCMenuItemImage::create(
                                                            "startbtn_normal.png",
                                                            "startbtn_touched.png",
                                                            this,
                                                            menu_selector(MenuScene::menuBinaryTreeCallback));
	CCMenu* pMenuBinaryTree= CCMenu::create(BinaryTreeBtn, NULL);
    
	pMenuBinaryTree->setScaleX(winSize.width/pMenuBinaryTree->getContentSize().width*0.5);
	pMenuBinaryTree->setScaleY(winSize.height/pMenuBinaryTree->getContentSize().height*0.6);
	pMenuBinaryTree->setPosition(ccp(winSize.width/2*0.9,winSize.height*0.5));
	this->addChild(pMenuBinaryTree,2);
    
	CCLabelTTF* pLabelBinaryTree = CCLabelTTF::create("BinaryTree", "Arial", 18);
	pLabelBinaryTree->setPosition(ccp(winSize.width *0.7, winSize.height*0.7));
	this->addChild(pLabelBinaryTree, 2);


	return true;
}

void MenuScene::menuBFSCallback( CCObject* pSender )
{
	CCScene* bfs = Bfs::scene();
	CCDirector::sharedDirector()->replaceScene(bfs);
}

void MenuScene::menuDFSCallback( CCObject* pSender )
{
	CCScene* dfs = Dfs::scene();
	CCDirector::sharedDirector()->replaceScene(dfs);
}

void MenuScene::menuAStarCallback( CCObject* pSender )
{
	CCScene* astar = Astar::scene();
	CCDirector::sharedDirector()->replaceScene(astar);
}
void MenuScene::menuFsmCallback( CCObject* pSender )
{
	CCScene* fsm = Fsm::scene();
	CCDirector::sharedDirector()->replaceScene(fsm);
}

void MenuScene::menuAabbCallback( CCObject* pSender )
{
	CCScene* aabb = Aabb::scene();
	CCDirector::sharedDirector()->replaceScene(aabb);
}

void MenuScene::menuCircleAndBoxCallback( CCObject* pSender )
{
	CCScene* circleAndBox = CircleAndBox::scene();
	CCDirector::sharedDirector()->replaceScene(circleAndBox);
}

void MenuScene::menuQsortCallback( CCObject* pSender )
{
	CCScene* qsort= Qsort::scene();
	CCDirector::sharedDirector()->replaceScene(qsort);
}
void MenuScene::menuBinarySearchCallback(CCObject* pSender)
{
    CCScene* binarySearch = BinarySearch::scene();
    CCDirector::sharedDirector()->replaceScene(binarySearch);
}
void MenuScene::menuAnimationCallback(CCObject* pSender)
{
    CCScene* animation = Animation::scene();
    CCDirector::sharedDirector()->replaceScene(animation);
}
void MenuScene::menuBinaryTreeCallback(CCObject* pSender)
{
    CCScene* binaryTree = BinaryTree::scene();
    CCDirector::sharedDirector()->replaceScene(binaryTree);
}