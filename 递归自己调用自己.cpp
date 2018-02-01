// 递归自己调用自己.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void f(int n)
{
	if(n==1)//必须知道什么时候自己不调用自己
	 printf("哈哈\n");
	
	else
		f(n-1);
}
	
int main()
{
	f(3);
    return 0;
}

