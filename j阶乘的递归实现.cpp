// j�׳˵ĵݹ�ʵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//�ٶ�n��ֵ��1�����1��ֵ
long  f(long n)
{
	if (1==n)//�����ٴ�һ��=���ᷢ�ֳ���
		return 1;
	else
		return f(n-1)*n;

}


int main()
{
	printf("%ld\n",f(3));
    return 0;
}

