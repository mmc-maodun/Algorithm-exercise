#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int *a,int *b)
{
	if(*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}

}

/*
算法导论版快排的Partition函数
*/
int Partition(int *A,int low,int high)
{
	if(A==NULL || low<0 || high<0 || low>=high)
		return -1;
	
	int small = low-1;
	int j;
	for(j=low;j<high;j++)
	{
		if(A[j] <= A[high])
		{
			++small;
			if(j != small)
				Swap(&A[j],&A[small]);
		}
	}
	++small;
	Swap(&A[small],&A[high]);
	return small;
}

int Random_Partition(int *A,int low,int high)
{
	//设置随机种子
	srand((unsigned)time(0));
	int index = low + rand()%(high-low+1);
	Swap(&A[index],&A[high]);
	return Partition(A,low,high);
}

 
/*
返回数组A中出现次数超过一半的数字
基于Partition函数的实现
*/
void MinKNum(int *A,int len,int k)
{
	if(A==NULL || len<1)
		return;

	int low = 0;
	int high = len-1;
	int index = Random_Partition(A,low,high);
	while(index != k-1)
	{
		if(index > k-1)
			index = Random_Partition(A,low,index-1);
		else
			index = Random_Partition(A,index+1,high);
	}
}

int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k) != EOF)
	{
		int *A = (int *)malloc(sizeof(int)*n);
		if(A == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",A+i);

		MinKNum(A,n,k);
		for(i=0;i<k;i++)
		{
			printf("%d ",A[i]);
		}
		printf("\n");
	}
	return 0;
}