/*
本程序采用数组模拟栈
*/
typedef int ElemType;
#define MAX 100000  //栈的深度
#include<stdio.h>
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
栈顶当前索引指针为top，Min数组最大深度也为MAX，
且Min的有效元素数与栈A中的元素个数相同，
它的对应位置用来保存栈A对应位置到栈底这一部分元素中的最小值
*/
void minAll(int *A,int *Min)
{
	if(top>MAX-1)
		return ;
	Min[0] = A[0];
	int i;
	for(i=1;i<=top;i++)
	{
		if(Min[i-1] > A[i])
			Min[i] = A[i];
		else
			Min[i] = Min[i-1];
	}
}

/*
返回栈顶为top时栈中元素的最小值
*/
int min(int *Min)
{
	return Min[top];
}

int main()
{

	int n;
	int A[MAX];
	int Min[MAX];

	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			char ci;
			while(getchar() != '\n')
				continue;
			scanf("%c",&ci);
			if(ci == 's')
			{
				ElemType k;
				scanf("%d",&k);
				push(A,k);
			}
			if(ci == 'o')
			{
				pop();
			}
			
			minAll(A,Min);
			if(top<0)
				printf("NULL\n");
			else
				printf("%d\n",min(Min));
		}
	}
	return 0;
}
