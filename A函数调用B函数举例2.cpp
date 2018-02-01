// A函数调用B函数举例2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int g(int);

int f(int n)
{
	if (n < 3)
		printf("哈哈\n");
	else
		n = f(n - 1);
	return n;
}

int g(int m)
{
	m = m * 2;
	return m;
}

int main()
{
	int val;

	val = f(5);
	

	return 0;
}


