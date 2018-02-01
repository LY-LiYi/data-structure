// 循环队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"malloc.h"

 typedef struct Queue//队列
{
	int  * pBase;//数组
	int  front;
	int rear;
}QUEUE;

void init(QUEUE *);//初始化
bool en_queue(QUEUE *,int val);//入队
void traverse_queue(QUEUE *);//遍历
bool full_queue(QUEUE *);//判断是否为满
bool out_queue(QUEUE*,int * pVal);//出队
bool  emupt_queue(QUEUE * pQ);//判断是否为空

int main()
{
	Queue	Q;
	int val;
	
	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2); 
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);

	traverse_queue(&Q);

	if (out_queue(&Q, &val))
	{
		printf("出队成功，队列出队的元素是:%d\n", val);
	}
	else
	{
		printf("出队失败");
	}

	traverse_queue(&Q);
    return 0;
}

void inin(QUEUE *pQ)//初始化
{
	pQ->pBase = (int *)malloc(sizeof(int)*6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool full_queue(QUEUE *pQ)//判断是否为满
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}


bool en_queue(QUEUE * pQ, int val)//入队 
{
	if (full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;//把值存入r的位置 
		pQ->rear = (pQ->rear + 1) % 6;//然后r+1指向下一个空闲位置

		return true;
	}
	
}

void traverse_queue(QUEUE * pQ)//遍历
{
	int i = pQ->front;

	while (i != pQ->rear)
	{
		printf("%d", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
	return;

}
bool emput_queue(QUEUE * pQ)//判断是否为空
{
	if (pQ->front == pQ->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool out_queue(QUEUE * pQ, int * pVal)//出队
{
	if(emput_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];//用来保存被删除的值
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}