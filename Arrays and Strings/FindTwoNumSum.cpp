/****************************************************************************************************
题目：输入一个无序的非负整数数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。
要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
例如输入数组1、7、4、11、6、15和数字15。由于4+11=15，因此输出4和11。
*****************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

/*
在无序数组A中找出和为sum的任意两个元素，保存在a和b中
*/
bool FindTwoNumSum(int *A,int len,int sum,int *a,int *b)
{
	if(A==NULL || len<2)
		return false;
	//各元素均被初始化为false的bool数组
	bool *B = (bool*)calloc(sum,sizeof(bool));
	if(B == NULL)
		exit(EXIT_FAILURE);
	int i;
	for(i=0;i<len;i++)
	{
		if(A[i]>sum)
			break;
		if(B[A[i]] == false)
			B[sum-A[i]] = true;
		else
		{
			*a = A[i];
			*b = sum-A[i];
			free(B);
			B = NULL;
			return true;
		}
	}
	free(B);
	B = NULL;
	return false;
}

int main()
{
	int A[] = {19,3,9,7,12,20,17,18,1,16};
	int len = 10;
	int sum = 24;
	int a,b;
	if(FindTwoNumSum(A,len,sum,&a,&b))
		printf("Find two nums,they are:\n%d and %d\n",a,b);
	else
		printf("Not find\n");
	return 0;
}
