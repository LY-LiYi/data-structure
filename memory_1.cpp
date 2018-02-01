// memory_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int f();
int main()
{
	int i = 10;
	
	i = f();
	printf("i=%d\n",i);

	for (i = 0; i < 2000; ++i)
		f();
}

int f()
{
	int j = 20;
	return j;

}
