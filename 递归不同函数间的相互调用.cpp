// �ݹ鲻ͬ��������໥����.cpp : �������̨Ӧ�ó������ڵ㡣
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

