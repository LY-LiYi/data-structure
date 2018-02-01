// 递归简介调用自己举例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void f(int n)
{
	g(n);

}

void g(int m)
{
	f(m);
}
int main()
{
    return 0;
}

