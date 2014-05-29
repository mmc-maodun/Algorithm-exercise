#include<stdio.h>
#include<stdlib.h>

/*
统计两个子数组之间的逆序对
*/
long long MergePairsBetweenArray(int *arr,int *brr,int start,int mid,int end)
{
	int i = mid;
	int j = end;
	int k = end;  //辅助数组的最后一位
	long long count = 0;

	//设置两个指针i,j分别从右往左依次比较，
	//将较大的依次放入辅助数组的右边
	while(i>=start && j>=mid+1)
	{
		if(arr[i] > arr[j])
		{
			count += j-mid;
			brr[k--] = arr[i--];
		}
		else
			brr[k--] = arr[j--];
	}

	//将其中一个数组中还剩下的元素拷贝到辅助数组中，
	//两个循环只会执行其中的一个
	while(i>=start)
		brr[k--] = arr[i--];
	while(j>=mid+1)
		brr[k--] = arr[j--];

	//从辅助数组中将元素拷贝到原数组中，使其有序排列
	for(i=end;i>k;i--)
		arr[i] = brr[i];

	return count;
}

/*
统计数组中的所有的逆序对
*/
long long CountMergePairs(int *arr,int *brr,int start,int end)
{
	long long PairsNum = 0;
	if(start<end)
	{
		int mid = (start+end)>>1;
		PairsNum += CountMergePairs(arr,brr,start,mid);	//统计左边子数组的逆序对
		PairsNum += CountMergePairs(arr,brr,mid+1,end);	//统计右边子数组的逆序对
		PairsNum += MergePairsBetweenArray(arr,brr,start,mid,end); //统计左右子数组间的逆序对
	}
	return PairsNum;
}

/*
将函数封装起来
*/
long long CountTotalPairs(int *arr,int len)
{
	if(arr==NULL || len<2)
		return 0;

	int *brr = (int *)malloc(len*sizeof(int));
	if(brr == NULL)
		exit(EXIT_FAILURE);

	long long sum = CountMergePairs(arr,brr,0,len-1);
	free(brr);
	brr = NULL;

	return sum;
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

		printf("%lld\n",CountTotalPairs(arr,n));

		free(arr);
		arr = NULL;
	}
	return 0;
}