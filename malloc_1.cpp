// malloc_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"malloc.h"
#pragma warning(disable:4996)



int main()
{
	int a[5] = { 4,10,2,8,6 };

	int len;
	printf("请输入你需要分配的数组长度：len=");
	scanf("%d", &len);
	int * pArr = (int *)malloc(sizeof(int)*len);
	//* pArr = 4;//类似于 a[0]=4
	//pArr[1] = 10; //；类似于a[1]=10;
	//printf("%d\n%d", *pArr, pArr[1]);

	for (int i = 0; i < 5; i++)
		scanf("%d", &pArr[i]);

	for (int i = 0; i < 5; i++)
		printf("%d\n", *(pArr + i));


	free(pArr);// 把pArr所代表的动态分配的20个字节的内存释放
	return 0;
}



