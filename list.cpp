// list.cpp : 定义控制台应用程序的入口点。
//链表

#include "stdafx.h"
#include"malloc.h"
#include"stdlib.h"

typedef struct Node
{
	int data; //数据域
	struct Node * pNext; //指针域
}NODE,*PNODE;//NODE等价于struct Node     PNODE等价于struct Node *

//函数声明
PNODE create_list(void);  //创建链表
void traverse_list(PNODE pHead);//遍历链表
bool is_empty(PNODE pHead);//判断链表是否为空
int  length_list(PNODE);//求长度
bool insert_list(PNODE, int, int);//插入  参数：链表 位置 值
bool delete_list(PNODE, int, int*);//删除 参数：链表 删除的节点 把下一个节点放入删除的位置
void sort_list(PNODE);//排序

int main(void)
{
	PNODE pHead = NULL;//等价于 struct Node * pHead=NULL；
	int val;

	pHead = create_list();//create_liat()功能：创建一个非循环单链表,并将该链表的头结点的地址赋给pHead
	traverse_list(pHead);//遍历链表

	//insert_list(pHead, 4, 33);
	//traverse_list(pHead);
	if (delete_list(pHead, 4, &val))
	{
		printf("删除成功，你删除的元素是:%d\n", val);
	}
	else
	{
		printf("删除失败，你删除的元素不存在");
	}

	traverse_list(pHead);
	
	//int len = length_list(pHead);
	//printf("链表的长度是%d\n", len);

	//sort_list(pHead);//排序
	//traverse_list(pHead);

/*	if (is_empty(pHead))	
	printf("链表为空\n");
	else
		printf("链表不为空");
	return 0;//判断链表是否为空
*/
}

PNODE create_list(void)//创建链表
{
	int len;//用来存放有效节点的个数
	int i;
	int val;//用来临时存放用户输入的节点的值


	//分配了一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败 程序终止\n");
		exit(-1);
	}
	PNODE pTail = pHead;//pTail和pHead都指向了头结点
	pTail->pNext = NULL;//把头结点的指针域清空 

	printf("请输入你需要生成的链表节点的个数：len=");
	scanf("%d", &len);

	for (i = 1; i <=len; ++i)
	{
		printf("请输入第%d个节点的值：", i);
		scanf("%d\n", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE)); //每循环一次pNew就造出了一个新节点
		if (NULL == pNew)
		{
			printf("分配失败 程序终止\n");
				exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;//pNew挂在尾结点后面 pNew就变成了尾结点
		pNew->pNext = NULL;//尾结点指向的下一个为空
		pTail = pNew;//pTail指向下一个新节点 pTail永远指向尾结点

	}
	return pHead;
}

void traverse_list(PNODE pHead)//遍历链表
{
	PNODE p = pHead->pNext;//p指向了pHead头结点指向的下一个节点

	while (NULL != p) //如果p指向的节点不为空
	{
		printf("%d", p->data);//输出p指向的节点的数据域
		p = p->pNext;//将p指向下一个节点
	}
	printf("\n");
	
	return;

}

bool is_empty(PNODE pHead)//判断链表是否为空
{
	if (NULL == pHead->pNext)
		return  true;
	else
		return  false;

}
 
int  length_list(PNODE pHead)//求长度 和上面的遍历相比多了一个++len
{
	PNODE p = pHead->pNext;
	int len = 0;

	while (NULL != p)
	{
		++len;
		p = p->pNext;
	}
	return  len;	
}

/*void sort_list(PNODE pHead)//排序
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;

	for ( p = pHead->pNext; i < len - 1; p = p->pNext)
	{
		for ( q = p->pNext; j < len;  q = q->pNext)
		{
			if (p->data > q->data)//类似于数值中的：a[i]>a[j]
			{
				t = p->data;//类似于数组中的：t = a[i];
				p->data = q->data;//类似于数组中的a[i] = a[j];
				q->data = t;//类似于数组中的：a[j]=t;
			}


		}

	}
	return;
}*/

//在pHead所指向链表的第pos个节点的前面插入一个新的节点，该节点的值是val,并且pos的值从1开始
bool insert_list(PNODE pHead, int pos, int val)//加入算法
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p&&i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p)
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态分配内存失败\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return  true;

}

bool delete_list(PNODE pHead, int pos, int * pVal)//删除算法
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext&&i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext)
		return false;

	PNODE q = p->pNext;
	*pVal = q->data;//删除前将值放到形参*pVal所指向的主函数变量中去，即定义一个局部变量vla用来存放删除掉的q的数据

	//删除p节点后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q =NULL;

	return true;
}
