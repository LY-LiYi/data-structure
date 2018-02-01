// j阶乘的递归实现.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//假定n的值是1或大于1的值
long  f(long n)
{
	if (1==n)//避免少打一个=不会发现出错
		return 1;
	else
		return f(n-1)*n;

}


int main()
{
	printf("%ld\n",f(3));
    return 0;
}

