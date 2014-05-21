#include<stdio.h>

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
判断是否有符合条件的排列，如果有的话，打印出一组
*/
bool CubVertex(int *A,int len,int begin)
{
	if(A==NULL || len!=8)
		return false;

	bool result = false;
	if(begin == len-1)
	{
		if(A[0]+A[1]+A[2]+A[3]==A[4]+A[5]+A[6]+A[7] &&
		A[0]+A[2]+A[4]+A[6]==A[1]+A[5]+A[3]+A[7] &&
		A[0]+A[1]+A[4]+A[5]==A[2]+A[3]+A[6]+A[7])
		{
			int i;
			for(i=0;i<len;i++)
				printf("%d ",A[i]);
			printf("\n");
			result =  true;
		}
	}
	else
	{
		int i;
		for(i=begin;i<len;i++)
		{
			swap(&A[begin],&A[i]);
			result = CubVertex(A,len,begin+1);
			if(result)
				break;
			swap(&A[begin],&A[i]);
		}
	}
	return result;
}

int main()
{
	int A[8] = {1,2,3,1,2,3,2,2};
	int B[8] = {1,2,3,1,8,3,2,2};
	if(CubVertex(A,8,0))
		printf("Yes\n");
	else
		printf("No\n");
	if(CubVertex(B,8,0))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}