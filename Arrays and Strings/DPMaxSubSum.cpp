#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool flag;

int MaxSubSum(int *arr,int len,int *indexBegin,int *indexEnd)
{
	if(arr==NULL || len<1)
	{
		flag = false;
		return -1;
	}

	int i;
	int MaxSum;
	int CurSum;
	int CurBegin; //当前的CurSum的开始处的索引
	int CurEnd;	 //当前的CurSum的结束处的索引
	for(i=0;i<len;i++)
	{
		if(i == 0)
		{
			//先用第一个元素初始化
			*indexBegin = 0;
			*indexEnd = 0;
			CurBegin = 0;
			CurEnd = 0;
			MaxSum = arr[i];
			CurSum = arr[i];
		}
		else
		{
			//前面的和小于0，抛弃前面的和，从当前元素重新开始计算
			if(CurSum < 0)
			{
				CurSum = arr[i];
				CurBegin = i;
				CurEnd = i;
			}
			else
			{
				CurSum += arr[i];
				CurEnd = i;
			}
			if(CurSum > MaxSum)
			{
				MaxSum = CurSum;
				//如果当前和大于前面出现的最大和，
				//则替换掉最大和的开始索引和结束索引
				*indexBegin = CurBegin;
				*indexEnd = CurEnd;
			}
		}
	}
	return MaxSum;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int *arr = (int *)malloc(sizeof(int)*n);
		if(arr == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr+i);

		flag = true;
		int indexBegin,indexEnd;
		int result = MaxSubSum(arr,n,&indexBegin,&indexEnd);	
		if(flag)
		{
			printf("%d ",result);
			printf("%d ",indexBegin);
			printf("%d\n",indexEnd);
		}

		free(arr);
		arr = NULL;
	}
	return 0;
}