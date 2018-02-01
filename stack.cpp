// stack.cpp : �������̨Ӧ�ó������ڵ㡣
//ջ

#include "stdafx.h"
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int  data;//������
	struct Node * pNext;//ָ����
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;//���� pTop��Զָ��ջ��Ԫ��
	PNODE pBottom;//�ײ� 

}STACK, *PSTACK;//PSTACK �ȼ��� struct Stack *

void init(PSTACK);//����ʱ�β�д��д����ν
void push(PSTACK,int);//���������Ǹ�ջѹԪ���Լ�Ԫ�ص�ֵ
void traverse(PSTACK);
bool pop(PSTACK, int *);

int main(void)
{
	STACK S;//STACK�ȼ���struct Stack���ڴ���������һ���ռ�S �ռ�������2��Ԫ����pTOP��pButtom
	//S�Ǿ�̬����� ����Ա�޷�����
	int val;

	init(&S);//Ŀ�������һ����ջ
	push(&S,1);//ѹջ
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S, 6);
	traverse(&S);//�������

	clear(&S);
	traverse(&S);//�������


	if (pop(&S,&val))//Ԫ�أ�1.����һ��ջ���г�ջ 2.�ѳ�ջ��Ԫ�ظ���������
	{
		printf("��ջ�ɹ�����ջ��Ԫ����%\n", val);
	}
	else
	{
		printf("��ջʧ��!\n");
	}
	traverse(&S);//�������
		

    return 0;
}

//��ʼ��ջ=��ʼ��ͷ���
void init(PSTACK pS)//�β�pS
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));//��̬�����ڴ�ʹpTopָ����һ����Ч��ͷ�ڵ�
	if (NULL == pS->pTop)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL; //pS->pBottom->pNext = NULL
	   //pTopָ����һ��ͷ��� �����ͷ����ָ����Ӧ���ǿյ�Ҳ����ͷ�����沢û�нڵ�
	}
}

void push(PSTACK pS,int val)//ѹջ
{
	PNODE PNew = (PNODE)malloc(sizeof(NODE));//����һ���µĽڵ�
	
	PNew->data = val;//��val��ֵ�����½ڵ��������
	PNew->pNext = pS->pTop;// pS->pTop���ܸĳ�pS->pBottom
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



//��pS��ָ���ջ��ջһ�β��ѳ�ջ��Ԫ�ش���pVal�β���ָ��ı����� �����ջʧ�ܷ���false���򷵻�true
bool pop(PSTACK pS,int * pVal)
{
	if (empty(pS))//pS�����ŵľ���s�ĵ�ַ
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;//�ѳ�ջԪ�ص�ֵ����val
		pS->pTop = r->pNext;
		free(r);
		r =NULL;

		return true;
	}
}

void clear(PSTACK pS)//�������
{
	if (empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;
		
		while (p != pS->pBottom)//p��qѭ��
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
}

