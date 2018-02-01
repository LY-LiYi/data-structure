// 链式二叉树遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"

struct BTNode
{
	char  data;//数据域
	struct BTNode * pLchild;//p是指针 L是左 child是孩子
	struct BTNode * pRchild;
};

struct BTNode * CreateBTree(void);
void PreTraverseBTree(struct BTNode * pT);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);

int main(void)
{
	struct BTNode * pT = CreateBTree();

	PreTraverseBTree(pT);//先序
	printf("\n");
	InTraverseBTree(pT);//中序
	printf("\n");
	PostTraverseBTree(pT);//后序

	while (1);
	return 0;
}
void PreTraverseBTree(struct BTNode * pT)//先序
{
	if (NULL != pT)//判断pT根节点是否为空
	{
		printf("%c", pT->data);

		if (NULL != pT->pLchild)//判断左子树是否为空
		{
			PreTraverseBTree(pT->pLchild);

		}
		if (NULL != pT->pRchild)//判断右子树是否为空
		{
			PreTraverseBTree(pT->pRchild);
		}
		//pT->pLchild//可以代表整个左子树

	}
}
			   
	 /* 伪算法：
	  先访问根节点
      再先序访问左子树
	  再先序访问右子树*/




void InTraverseBTree(struct BTNode * pT)//中序
{
	
		if (NULL != pT)//判断pT根节点是否为空
		{

			if (NULL != pT->pLchild)//判断左子树是否为空
			{
				InTraverseBTree(pT->pLchild);

			}

			printf("%c", pT->data);

			if (NULL != pT->pRchild)//判断右子树是否为空
			{
				InTraverseBTree(pT->pRchild);
			}
			//pT->pLchild//可以代表整个左子树

		}
}
	
void PostTraverseBTree(struct BTNode * pT)//后序
{

	if (NULL != pT)//判断pT根节点是否为空
	{

		if (NULL != pT->pLchild)//判断左子树是否为空
		{
			PostTraverseBTree(pT->pLchild);

		}

		if (NULL != pT->pRchild)//判断右子树是否为空
		{
			PostTraverseBTree(pT->pRchild);
		}

		printf("%c", pT->data);
		//pT->pLchild//可以代表整个左子树

	}
}


struct BTNode * CreateBTree(void)
{
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pRchild = pE;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}
