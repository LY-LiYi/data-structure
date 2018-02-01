// type.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}*PSTU,STU;//等价于ST代表了struct Student，PST代表了struct Student *
int main(void)
{
	STU st;//相当于struct Student st；
	PSTU ps = &st;//struct Student * ps=&st;
	ps->sid = 99;
	printf("%d\n",ps->sid);
	return 0;
}

