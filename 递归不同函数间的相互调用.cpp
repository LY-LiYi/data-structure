// 递归不同函数间的相互调用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void f();
void g();
void k();


void f()
{
	printf("FFFFF\n");
	g();
	printf("11111\n");
}

void  g()
{
	printf("GGGGG\n");
	k();
	printf("22222");
}

void k()
{
	printf("KKKKK\n");
}

int main()
{
   
	f();
	return 0;
}

