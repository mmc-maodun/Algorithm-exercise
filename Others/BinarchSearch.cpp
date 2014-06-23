#include<stdio.h>
#include<stdlib.h>

/*
非递归实现,返回对应的序号
*/
int BinarySearch(int *arr,int len,int key)
{
	if(arr==NULL || len<1)
		return -1;

	int low = 0;
	int high = len-1;
	while(low <= high)
	{
		int mid = (low+high)>>1;
		if(key == arr[mid])
			return mid;
		else if(key < arr[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

/*
递归实现,返回对应的序号
*/
int BSearch(int *arr,int low,int high,int key)
{
	if(arr==NULL || low>high)
		return -1;
	
	int mid = (low+high)>>1;
	if(arr[mid] == key)
		return mid;
	else if(arr[mid] > key)
		return BSearch(arr,low,mid-1,key);
	else
		return BSearch(arr,mid+1,high,key);
}

/*
将递归实现的方法封装起来
*/
int BinSearch(int *arr,int len,int key)
{
	return BSearch(arr,0,len-1,key);
}

int main()
{
	int n,key;
	while(scanf("%d %d",&n,&key) != EOF)
	{
		int *arr = (int *)malloc(n*sizeof(int));
		if(arr == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr+i);

		int result = BinSearch(arr,n,key);
		if(result == -1)
			printf("Not Find!\n");
		else
			printf("%d\n",arr[result]);
	}
	return 0;
}
