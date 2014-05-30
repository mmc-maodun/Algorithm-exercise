#include<stdio.h>
#include<stdbool.h>

/*
返回num的最低位的1，其他各位都为0
*/
int FindFirstBit1(int num)
{
	//二者与后得到的数，将num最右边的1保留下来，其他位的全部置为了0
	return num & (-num);
}

/*
判断data中特定的位是否为1，
这里的要判断的特定的位由res确定，
res中只有一位为1，其他位均为0，由FindFirstBit1函数返回，
而data中要判断的位便是res中这唯一的1所在的位
*/
bool IsBit1(int data,int res)
{
	return ((data&res)==0) ? false:true;
}

void FindNumsAppearOnce(int *arr,int len,int *num1,int *num2)
{
	if(arr==NULL || len<2)
		return;

	int i;
	int AllXOR = 0;
	//全部异或
	for(i=0;i<len;i++)
		AllXOR ^= arr[i];

	int res = FindFirstBit1(AllXOR);

	*num1 = *num2 = 0;
	for(i=0;i<len;i++)
	{
		if(IsBit1(arr[i],res))
			*num1 ^= arr[i];
		else
			*num2 ^= arr[i];
	}
}

int main()
{
	static int arr[1000000];
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr+i);

		int num1,num2;
		FindNumsAppearOnce(arr,n,&num1,&num2);
		if(num1 < num2)
			printf("%d %d\n",num1,num2);
		else
			printf("%d %d\n",num2,num1);
	}
	return 0;
}