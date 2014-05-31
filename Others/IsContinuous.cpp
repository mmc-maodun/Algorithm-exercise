#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int mycompare(const void *data1,const void *data2)
{
	return *(int *)data1 - *(int *)data2;
}


bool IsContinuous(int *arr,int len)
{
	if(arr==NULL || len<1)
		return false;

	qsort(arr,len,sizeof(int),mycompare);

	int NumOf0 = 0;	    //0的个数
	int NumOfGap = 0;  //空缺的个数
	int i;
	for(i=0;i<len-1;i++)
	{
		if(arr[i] == 0)
			NumOf0++;
		else
		{
			if(arr[i] == arr[i+1])
				return false;
			else
				NumOfGap += arr[i+1]-arr[i]-1;
		}
	}
	return (NumOfGap>NumOf0)?false:true;
}

int main()
{
	int n;
	int arr[15];
	memset(arr,0,sizeof(arr));
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr+i);

		bool can = IsContinuous(arr,n);
		if(can)
			printf("So Lucky!\n");
		else
			printf("Oh My God!\n");
	}
	return 0;
}