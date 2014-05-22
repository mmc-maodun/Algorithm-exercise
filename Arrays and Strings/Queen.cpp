#include<stdio.h>

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int count = 0;
/*
如果有符合条件的摆法，打印出所有的摆法，否则，什么也不打印
*/
void CubVertex(int *A,int len,int begin)
{
	if(A==NULL || len!=8)
		return;

	if(begin == len-1)
	{
		int i,j;
		bool can = true;	//是否又符合条件的摆法
		for(i=0;i<len;i++)
			for(j=i+1;j<len;j++)
				if(i-j==A[i]-A[j] || i-j==A[j]-A[i])
				{
					//如果任意两个在一条对角线上，则不符合
					can = false;
					break;
				}
		//有符合的摆法，就打印出来
		if(can)
		{
			for(i=0;i<len;i++)
				printf("%d ",A[i]);
			printf("\n");
			count++;
		}
		return;
	}


	int i;
	for(i=begin;i<len;i++)
	{
		swap(&A[begin],&A[i]);
		CubVertex(A,len,begin+1);
		swap(&A[begin],&A[i]);
	}
}

int main()
{
	int A[8] = {0,1,2,3,4,5,6,7};
	CubVertex(A,8,0);
	printf("共有%d种摆法\n",count);
	return 0;
}
