// type.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}* PST;//PST等价于struct Student *

int main(void)
{
	struct Student st;
		PST ps = &st;
		ps->sid = 99;
		printf("%d\n", ps->sid);

	return 0;
}

