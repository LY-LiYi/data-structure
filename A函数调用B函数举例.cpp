// A��������B��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int f(int n)
{
	n += 2;//n=n+2
	return n;
}

int main()
{
	int val;

	val = f(5);
	printf("%d\n", val);

    return 0;
}

