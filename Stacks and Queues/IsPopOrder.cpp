/*
本程序采用数组模拟栈
*/
typedef int ElemType;
#define MAX 100000 //栈的深度
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int top = -1;
/*
在栈顶索引指针为top时，向栈A中压入数据data
*/
bool push(int *A,ElemType data)
{
	if(top>=MAX-1 || top<-1)
		return false;

	A[++top] = data;
	return true;
}

/*
在栈顶索引指针为top时，出栈
*/
bool pop()
{
	if(top<0)
		return false;

	top--;
	return true;
}

/*
判断popList是否是pushList的弹出序列
*/
bool IsPopOrder(int *pushList,int *popList,int len,int *stack)
{
	if(popList==NULL || pushList==NULL || len<1)
		return false;

	int i;
	int pushIndex = 0;
	for(i=0;i<len;i++)
	{
		while(top==-1 || stack[top] != popList[i])
		{
			//如果没有元素可以push了，就说明不符合
			if(pushIndex == len)
				return false;
			push(stack,pushList[pushIndex++]);
		}
		pop();
	}
	return true;
}

int main()
{
	int n;
	int stack[MAX]; //辅助栈
	while(scanf("%d",&n) != EOF)
	{
		int *pushList = (int *)malloc(n*sizeof(int));
		if(pushList == NULL)
			exit(EXIT_FAILURE);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",pushList+i);

		int *popList = (int *)malloc(n*sizeof(int));
		if(popList == NULL)
			exit(EXIT_FAILURE);
		for(i=0;i<n;i++)
			scanf("%d",popList+i);

		if(IsPopOrder(pushList,popList,n,stack))
			printf("Yes\n");
		else
			printf("No\n");

		free(pushList);
		pushList = NULL;
		free(popList);
		popList = NULL;
	}
	return 0;
}