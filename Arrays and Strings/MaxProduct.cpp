#include<stdio.h>

bool flag;
long long MaxProduct(int *arr,int len)
{
	if(arr==NULL || len<1)
	{ 
		flag = false;
		return 0;
	}

	int minus = 0;	//负数个数
	int plus = 0;	//正数个数
	int zero = 0;	//0的个数
	int minAbsMinus = (signed int)0x80000000;	//绝对值最小的负整数,先初始化为最小的int负数
	int maxAbsMinus = -1;						//绝对值最大的负整数，先初始化为最大的负整数
	int minPlus = 0x7FFFFFFF;					//最小的正整数，先初始化为最大的int正数

	int i;
	for(i=0;i<len;i++)
	{
		if(arr[i] == 0)
			zero++;
		else if(arr[i] < 0)
			minus++;
		else
			plus++;

		if(arr[i]<0 && arr[i]>minAbsMinus)
			minAbsMinus = arr[i];
		if(arr[i]<0 && arr[i]<maxAbsMinus)
			maxAbsMinus = arr[i];
		if(arr[i]>0 && arr[i]<minPlus)
			minPlus = arr[i];	
	}

	int outNum;		//不参与乘积的数
	long long result = 1;	//n-1个数的最大乘积

	//0的个数大于1的情况，这时任意n-1个数的乘积都为0，
	if(zero > 1)
		return 0;
	//如果有一个0，则需要根据正负数的个数来决定
	if(zero == 1)
	{
		//如果负数的个数为偶数个，
		//则去掉0后的n-1个数的乘积为正，即为最大值
		if((minus&1) == 0)
			outNum = 0;
		//如果负数的个数为奇数个，
		//则去掉0后的n-1个数的乘积为负，因此最大值应该为0，
		//去掉任一个非0元素即可
		else	
			return 0;
	}
	//如果没有0，则需要根据正负数的个数来决定
	else
	{
		//如果负数个数为奇数个，则去掉一个负数后，剩下的n-1个元素的乘积为正，
		//此时去掉绝对值最小的负数，剩下的n-1个数的乘积便最大
		if((minus&1) != 0)
			outNum = minAbsMinus;
		//如果负数个数为偶数个，这时候要分两种情况，
		//数组中有正数和没正数
		else
		{
			//如果数组中没有正数，则n-1个负数的乘积肯定为负数，
			//去掉绝对值最大的负数，便可得n-1个负数乘积的最大值
			if(plus == 0)
					outNum = maxAbsMinus;
			//如果数组中有正数，则去掉最小的正数，便可得n-1个数乘积最大值
			else
				outNum = minPlus;
		}
	}

	//计算乘积
	for(i=0;i<len;i++)
	{
		if(arr[i] != outNum)
			result *= arr[i];
	}
	
	return result;
}


int main()
{
	int arr[6] = {-3,-7,-1,-2,-6,-4};
	flag = true;
	if(flag)
		printf("%lld\n",MaxProduct(arr,6));
	return 0;
}
