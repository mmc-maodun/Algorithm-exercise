/****************************************************************************************************
题目：输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。
要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。
*****************************************************************************************************/
#include<stdio.h>

/*
在升序数组A中找出和为sum的任意两个元素，保存在a和b中
*/
bool FindTwoNumSum(int *A,int len,int sum,int *a,int *b)
{
	if(A==NULL || len<2)
		return false;
	int low = 0;
	int high = len-1;
	while(low<high)
	{
		if(A[low]+A[high] == sum)
		{
			*a = A[low];
			*b = A[high];
			return true;
		}
		else if(A[low]+A[high] < sum)
			low++;
		else
			high--;
	}
	return false;
}

int main()
{
	int A[] = {1,3,7,9,12,15,17,18,19,20};
	int len = 10;
	int sum = 24;
	int a,b;
	if(FindTwoNumSum(A,len,sum,&a,&b))
		printf("Find two nums,they are:\n%d and %d\n",a,b);
	else
		printf("Not find\n");
	return 0;
}