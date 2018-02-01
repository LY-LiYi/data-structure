// A函数调用B函数举例.cpp : 定义控制台应用程序的入口点。
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

