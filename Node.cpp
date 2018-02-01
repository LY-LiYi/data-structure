// Node.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef struct Node  
{
	int date;// 数据域;
	struct Node * pNext; //指针域;

}NODE,*PNODE;//NODE等价于struct Node，PNODE等价于struct Node *类型

int main()
{
    return 0;
}

