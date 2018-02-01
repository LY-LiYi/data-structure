// stack.cpp : 定义控制台应用程序的入口点。
//栈

#include "stdafx.h"
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int  data;//数据域
	struct Node * pNext;//指针域
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;//顶部 pTop永远指向栈顶元素
	PNODE pBottom;//底部 

}STACK, *PSTACK;//PSTACK 等价于 struct Stack *

void init(PSTACK);//声明时形参写不写无所谓
void push(PSTACK,int);//参数：向那个栈压元素以及元素的值
void traverse(PSTACK);
bool pop(PSTACK, int *);

int main(void)
{
	STACK S;//STACK等价于struct Stack；内存里面有了一个空间S 空间里面有2个元素是pTOP和pButtom
	//S是静态分配的 程序员无法销毁
	int val;

	init(&S);//目的是造出一个空栈
	push(&S,1);//压栈
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S, 6);
	traverse(&S);//遍历输出

	clear(&S);
	traverse(&S);//遍历输出


	if (pop(&S,&val))//元素：1.对那一个栈进行出栈 2.把出栈的元素给保存起来
	{
		printf("出栈成功，出栈的元素是%\n", val);
	}
	else
	{
		printf("出栈失败!\n");
	}
	traverse(&S);//遍历输出
		

    return 0;
}

//初始化栈=初始化头结点
void init(PSTACK pS)//形参pS
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));//动态分配内存使pTop指向了一个有效的头节点
	if (NULL == pS->pTop)
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL; //pS->pBottom->pNext = NULL
	   //pTop指向了一个头结点 而这个头结点的指针域应该是空的也就是头结点后面并没有节点
	}
}

void push(PSTACK pS,int val)//压栈
{
	PNODE PNew = (PNODE)malloc(sizeof(NODE));//有了一个新的节点
	
	PNew->data = val;//把val的值放入新节点的数据域
	PNew->pNext = pS->pTop;// pS->pTop不能改成pS->pBottom
	pS->pTop = PNew;

	return ;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;

	while (p != pS->pBottom)
	{
		printf("%d", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;}



//把pS所指向的栈出栈一次并把出栈的元素存入pVal形参所指向的变量中 如果出栈失败返回false否则返回true
bool pop(PSTACK pS,int * pVal)
{
	if (empty(pS))//pS本身存放的就是s的地址
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;//把出栈元素的值赋给val
		pS->pTop = r->pNext;
		free(r);
		r =NULL;

		return true;
	}
}

void clear(PSTACK pS)//清空数据
{
	if (empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;
		
		while (p != pS->pBottom)//p和q循环
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
}

