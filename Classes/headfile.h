#ifndef __HEADFILE__
#define __HEADFILE__

#define  MAXVAL 1000000

#include "cocos2d.h"
#include <queue>
#include <stack>
#include <list>
using namespace cocos2d;


//搜索
struct Node
{
	int x,y;
	int step;
    //
    int f;
};
//有限状态机
enum{
	State_IsRun,
	State_FindBox,
	State_HideBubble
};
//a*结构体
struct Point
{
	int px,py;
	int x,y;
	int F,G,H;
};
//矩阵
struct NewRect
{
	CCSprite* back;
	float x,y,h,w;
	int step;
	int dir;
};
//圆
struct NewCircle
{
	CCSprite* back;
	float x,y;
	float r;
	int step;
	int dir;
};


#endif