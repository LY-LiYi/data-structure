// malloc_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"malloc.h"
#pragma warning(disable:4996)



int main()
{
	int a[5] = { 4,10,2,8,6 };

	int len;
	printf("����������Ҫ��������鳤�ȣ�len=");
	scanf("%d", &len);
	int * pArr = (int *)malloc(sizeof(int)*len);
	//* pArr = 4;//������ a[0]=4
	//pArr[1] = 10; //��������a[1]=10;
	//printf("%d\n%d", *pArr, pArr[1]);

	for (int i = 0; i < 5; i++)
		scanf("%d", &pArr[i]);

	for (int i = 0; i < 5; i++)
		printf("%d\n", *(pArr + i));


	free(pArr);// ��pArr������Ķ�̬�����20���ֽڵ��ڴ��ͷ�
	return 0;
}



