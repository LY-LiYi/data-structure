// 递归的值可以增加但处理的规模在递减举例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int g(int);

int f(int n)
{
	if (n >7 )
		printf("哈哈\n");
	else
		n = f(n + 1);
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



