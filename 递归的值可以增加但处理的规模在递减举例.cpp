// �ݹ��ֵ�������ӵ�����Ĺ�ģ�ڵݼ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int g(int);

int f(int n)
{
	if (n >7 )
		printf("����\n");
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



