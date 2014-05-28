#include<stdio.h>
#include<stdlib.h>

/*
二分查找法计算key出现的次数
*/
int CountTimesInArrays(int *arr,int len,int key)
{
	if(arr==NULL || len<1)
		return 0;

	int start = 0;
	int end = len-1;
	int mid;
	while(start <= end)
	{
		mid = (start+end)>>1;
		if(arr[mid] == key)
			break;
		else if(arr[mid] > key)
			end = mid-1;
		else 
			start = mid+1;
	}


	//包含了出现0次的情况
	int times = 0;
	if(start <= end)
	{
		int i;
		times = 1;
		for(i=mid+1;i<=end;i++)
			if(arr[i] == key)
				times++;
		for(i=mid-1;i>=start;i--)
			if(arr[i] == key)
				times++;
	}
	return times;
} 

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int *arr = (int *)malloc(n*sizeof(int));
		if(arr == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr+i);
		int m;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			int k;
			scanf("%d",&k);
			printf("%d\n",CountTimesInArrays(arr,n,k));
		}

		free(arr);
		arr = NULL;
	}
	return 0;
}