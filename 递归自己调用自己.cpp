// �ݹ��Լ������Լ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void f(int n)
{
	if(n==1)//����֪��ʲôʱ���Լ��������Լ�
	 printf("����\n");
	
	else
		f(n-1);
}
	
int main()
{
	f(3);
    return 0;
}

