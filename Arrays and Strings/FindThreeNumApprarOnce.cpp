#include<stdio.h>

/*
通过扫面每一位，先找出一个只出现一次的数
*/
int FindOneNumAppearOnce(int *arr,int len)
{
	int count1 = 0;	//某一位上1的个数
	int count0 = 0; //某一位上0的个数
	int temp1 = 0;	//某一位为1的所有数相异或的结果
	int temp0 = 0;	//某一位为0的所有数相异或的结果

	int i,j;
	for(i=0;i<8*sizeof(int);i++)	//循环计算每一位的以上四个数据
	{
		count1 = count0 = temp1 = temp0 = 0;//每次计算下一位时清零
		for(j=0;j<len;j++)
		{	
			//每次向左移一位进行计算
			if(arr[j] & (1<<i))	//该位为1时
			{
				temp1 ^= arr[j];
				count1++;
			}
			else
			{
				temp0 ^= arr[j];
				count0++;
			}
		}

		if(temp1 & 1)	//某位上有奇数个1
		{
			if(temp0 == 0)	//此时3个不同数的该位都为1
				continue;
			else			//此时3个不同数的该位有1个1，2个0
				return temp1;
		}
		else	//某位上有偶数个1
		{
			if(temp1 == 0)	//此时3个不同数的该位都为0
				continue;
			else			//此时3个不同数的该位有1个0，2个1
				return temp0;
		}
	}
}

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

void FindTwoNumsAppearOnce(int *arr,int len,int *num1,int *num2)
{

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

/*
交换两个int变量
*/
void Swap(int *a,int *b)
{
	if(*a != *b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

/*
找出这三个只出现一次的数字
*/
void FindThreeNumsAppearOnce(int *arr,int len,int *num1,int *num2,int *num3)
{
	if(arr==NULL || len<3)
		return;

	*num1 = FindOneNumAppearOnce(arr,len);

	//找到第一个找出的数字，并与最后一个元素交换，便于接下来剩下的两个数字
	int i;
	for(i=0;i<len;i++)
		if(*num1 == arr[i])
			break;
	Swap(&arr[i],&arr[len-1]);

	FindTwoNumsAppearOnce(arr,len-1,num2,num3);
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

		int num1,num2,num3;
		FindThreeNumsAppearOnce(arr,n,&num1,&num2,&num3);
		printf("%d %d %d\n",num1,num2,num3);
	}
	return 0;
}