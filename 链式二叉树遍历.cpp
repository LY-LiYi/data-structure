// ��ʽ����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "malloc.h"

struct BTNode
{
	char  data;//������
	struct BTNode * pLchild;//p��ָ�� L���� child�Ǻ���
	struct BTNode * pRchild;
};

struct BTNode * CreateBTree(void);
void PreTraverseBTree(struct BTNode * pT);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);

int main(void)
{
	struct BTNode * pT = CreateBTree();

	PreTraverseBTree(pT);//����
	printf("\n");
	InTraverseBTree(pT);//����
	printf("\n");
	PostTraverseBTree(pT);//����

	while (1);
	return 0;
}
void PreTraverseBTree(struct BTNode * pT)//����
{
	if (NULL != pT)//�ж�pT���ڵ��Ƿ�Ϊ��
	{
		printf("%c", pT->data);

		if (NULL != pT->pLchild)//�ж��������Ƿ�Ϊ��
		{
			PreTraverseBTree(pT->pLchild);

		}
		if (NULL != pT->pRchild)//�ж��������Ƿ�Ϊ��
		{
			PreTraverseBTree(pT->pRchild);
		}
		//pT->pLchild//���Դ�������������

	}
}
			   
	 /* α�㷨��
	  �ȷ��ʸ��ڵ�
      ���������������
	  ���������������*/




void InTraverseBTree(struct BTNode * pT)//����
{
	
		if (NULL != pT)//�ж�pT���ڵ��Ƿ�Ϊ��
		{

			if (NULL != pT->pLchild)//�ж��������Ƿ�Ϊ��
			{
				InTraverseBTree(pT->pLchild);

			}

			printf("%c", pT->data);

			if (NULL != pT->pRchild)//�ж��������Ƿ�Ϊ��
			{
				InTraverseBTree(pT->pRchild);
			}
			//pT->pLchild//���Դ�������������

		}
}
	
void PostTraverseBTree(struct BTNode * pT)//����
{

	if (NULL != pT)//�ж�pT���ڵ��Ƿ�Ϊ��
	{

		if (NULL != pT->pLchild)//�ж��������Ƿ�Ϊ��
		{
			PostTraverseBTree(pT->pLchild);

		}

		if (NULL != pT->pRchild)//�ж��������Ƿ�Ϊ��
		{
			PostTraverseBTree(pT->pRchild);
		}

		printf("%c", pT->data);
		//pT->pLchild//���Դ�������������

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
