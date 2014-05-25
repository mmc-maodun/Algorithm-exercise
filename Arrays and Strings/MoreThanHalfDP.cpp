#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool IsExisted;

/*
判断关键字key在数组A中出现的次数是否超过一半
*/
bool IsMoreThanHalf(int *A,int len,int key)
{
	int times = 0;
	int i;
	for(i=0;i<len;i++)
		if(A[i] == key)
			times++;
	if(2*times <= len)
		return false;
	else
		return true;
}

/*
找出出现次数超过一半的数字
*/
int MoreThanHalfDP(int *A,int len)
{
	if(A==NULL || len<1)
	{
		IsExisted = false;
		return -1;
	}
	
	int result = A[0];
	int times = 1;
	int i;
	for(i=1;i<len;++i)
	{
		if(times == 0)
		{
			result = A[i];
			times = 1;
		}
		else if(A[i] == result)
			++times;
		else
			--times;
	}
	if(!IsMoreThanHalf(A,len,result))
	{
		IsExisted = false;
		return -1;
	}
	return result;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int *A = (int *)malloc(sizeof(int)*n);
		if(A == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",A+i);

		IsExisted = true;
		int key = MoreThanHalfDP(A,n);
		if(IsExisted)
			printf("%d\n",key);
		else
			printf("-1\n");
	}
	return 0;
}