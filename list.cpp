// list.cpp : �������̨Ӧ�ó������ڵ㡣
//����

#include "stdafx.h"
#include"malloc.h"
#include"stdlib.h"

typedef struct Node
{
	int data; //������
	struct Node * pNext; //ָ����
}NODE,*PNODE;//NODE�ȼ���struct Node     PNODE�ȼ���struct Node *

//��������
PNODE create_list(void);  //��������
void traverse_list(PNODE pHead);//��������
bool is_empty(PNODE pHead);//�ж������Ƿ�Ϊ��
int  length_list(PNODE);//�󳤶�
bool insert_list(PNODE, int, int);//����  ���������� λ�� ֵ
bool delete_list(PNODE, int, int*);//ɾ�� ���������� ɾ���Ľڵ� ����һ���ڵ����ɾ����λ��
void sort_list(PNODE);//����

int main(void)
{
	PNODE pHead = NULL;//�ȼ��� struct Node * pHead=NULL��
	int val;

	pHead = create_list();//create_liat()���ܣ�����һ����ѭ��������,�����������ͷ���ĵ�ַ����pHead
	traverse_list(pHead);//��������

	//insert_list(pHead, 4, 33);
	//traverse_list(pHead);
	if (delete_list(pHead, 4, &val))
	{
		printf("ɾ���ɹ�����ɾ����Ԫ����:%d\n", val);
	}
	else
	{
		printf("ɾ��ʧ�ܣ���ɾ����Ԫ�ز�����");
	}

	traverse_list(pHead);
	
	//int len = length_list(pHead);
	//printf("����ĳ�����%d\n", len);

	//sort_list(pHead);//����
	//traverse_list(pHead);

/*	if (is_empty(pHead))	
	printf("����Ϊ��\n");
	else
		printf("����Ϊ��");
	return 0;//�ж������Ƿ�Ϊ��
*/
}

PNODE create_list(void)//��������
{
	int len;//���������Ч�ڵ�ĸ���
	int i;
	int val;//������ʱ����û�����Ľڵ��ֵ


	//������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("����ʧ�� ������ֹ\n");
		exit(-1);
	}
	PNODE pTail = pHead;//pTail��pHead��ָ����ͷ���
	pTail->pNext = NULL;//��ͷ����ָ������� 

	printf("����������Ҫ���ɵ�����ڵ�ĸ�����len=");
	scanf("%d", &len);

	for (i = 1; i <=len; ++i)
	{
		printf("�������%d���ڵ��ֵ��", i);
		scanf("%d\n", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE)); //ÿѭ��һ��pNew�������һ���½ڵ�
		if (NULL == pNew)
		{
			printf("����ʧ�� ������ֹ\n");
				exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;//pNew����β������ pNew�ͱ����β���
		pNew->pNext = NULL;//β���ָ�����һ��Ϊ��
		pTail = pNew;//pTailָ����һ���½ڵ� pTail��Զָ��β���

	}
	return pHead;
}

void traverse_list(PNODE pHead)//��������
{
	PNODE p = pHead->pNext;//pָ����pHeadͷ���ָ�����һ���ڵ�

	while (NULL != p) //���pָ��Ľڵ㲻Ϊ��
	{
		printf("%d", p->data);//���pָ��Ľڵ��������
		p = p->pNext;//��pָ����һ���ڵ�
	}
	printf("\n");
	
	return;

}

bool is_empty(PNODE pHead)//�ж������Ƿ�Ϊ��
{
	if (NULL == pHead->pNext)
		return  true;
	else
		return  false;

}
 
int  length_list(PNODE pHead)//�󳤶� ������ı�����ȶ���һ��++len
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

/*void sort_list(PNODE pHead)//����
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;

	for ( p = pHead->pNext; i < len - 1; p = p->pNext)
	{
		for ( q = p->pNext; j < len;  q = q->pNext)
		{
			if (p->data > q->data)//��������ֵ�еģ�a[i]>a[j]
			{
				t = p->data;//�����������еģ�t = a[i];
				p->data = q->data;//�����������е�a[i] = a[j];
				q->data = t;//�����������еģ�a[j]=t;
			}


		}

	}
	return;
}*/

//��pHead��ָ������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵ��val,����pos��ֵ��1��ʼ
bool insert_list(PNODE pHead, int pos, int val)//�����㷨
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
		printf("��̬�����ڴ�ʧ��\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return  true;

}

bool delete_list(PNODE pHead, int pos, int * pVal)//ɾ���㷨
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
	*pVal = q->data;//ɾ��ǰ��ֵ�ŵ��β�*pVal��ָ���������������ȥ��������һ���ֲ�����vla�������ɾ������q������

	//ɾ��p�ڵ����Ľڵ�
	p->pNext = p->pNext->pNext;
	free(q);
	q =NULL;

	return true;
}
