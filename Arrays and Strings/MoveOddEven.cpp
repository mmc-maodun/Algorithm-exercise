#include<stdio.h>
#include<stdlib.h>

void MoveOddEven(int *A,int n)
{
	if(A==NULL || n<2)
		return;
	int *B = (int *)malloc(n*sizeof(int));	
	if(B == NULL)
		exit(EXIT_FAILURE);

	int i;
	int j = 0;
	for(i=0;i<n;i++)
	{
		//奇数
		if((A[i]&1) != 0)
			B[j++] = A[i];
	}
	for(i=0;i<n;i++)
	{
		//偶数
		if((A[i]&1) == 0)
			B[j++] = A[i];
	}

	for(i=0;i<n;i++)
	{
		A[i] = B[i];
	}

	free(B);
	B = NULL;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	int *A = (int *)malloc(n*sizeof(int));
	if(A == NULL)
		exit(EXIT_FAILURE);
	for(i=0;i<n;i++)
		scanf("%d",A+i);
	MoveOddEven(A,n);
	for(i=0;i<n;i++)
	{
		//注意输出格式
		if(i == n-1)
			printf("%d\n",A[i]);
		else
			printf("%d ",A[i]);
	}
	free(A);
	A = NULL;
	return 0;
}