// �ݹ�������Լ�����.cpp : �������̨Ӧ�ó������ڵ㡣
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

