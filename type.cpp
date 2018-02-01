// type.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

typedef int  ZHANGSAN;//为int再重新多取一个名字,ZHANGSAN等价于int

typedef struct Student 
{
	int sid;
	char name[100];
	char sex;
}ST;

int main()
{
	//int i = 10;
	//ZHANGSAN j = 20;
	//printf("%d\n", j);

	struct Student st;//等价于 ST st
	struct Student * ps = &st;//等价于ST＊ｐｓ

	ST st2;
	st2.sid = 200;
	printf("%d\n",st2.sid);

    return 0;
}

