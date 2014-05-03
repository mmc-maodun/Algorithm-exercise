#include<stdio.h>

/*
常规方法,时间复杂度O（n*n）
先从第一个元素开始向后累加，
每次累加后与之前的和比较，保留最大值，
再从第二个元素开始向后累加，以此类推。
*/
int MaxSubSum1(int *arr,int len)
{
	int i,j;
	int MaxSum = 0;
	//每次开始累加的起始位置的循环
	for(i=0;i<len;i++)
	{
		int CurSum = 0;
		//向后累加的循环
		for(j=i;j<len;j++)
		{
			CurSum += arr[j];
			if(CurSum > MaxSum)
				MaxSum = CurSum;
		}
	}
	return MaxSum;
}

/*
求三个数中的最大值
*/
int Max3(int a,int b,int c)
{
	int Max = a;
	if(b > Max)
		Max = b;
	if(c > Max)
		Max = c;
	return Max;
}

/*
次优算法，采用分治策略
*/
int MaxSubSum2(int *arr,int left,int right)
{
	int MaxLeftSum,MaxRightSum;	//左右边的最大和
	int MaxLeftBorderSum,MaxRightBorderSum;	//含中间边界的左右部分最大和
	int LeftBorderSum,RightBorderSum;	//含中间边界的左右部分当前和
	int i,center;

	//递归到最后的基本情况
	if(left == right)
		if(arr[left]>0)
			return arr[left];
		else
			return 0;

	//求含中间边界的左右部分的最大值
	center = (left + right)/2;
	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for(i=center;i>=left;i--)
	{
		LeftBorderSum += arr[i];
		if(LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for(i=center+1;i<=right;i++)
	{
		RightBorderSum += arr[i];
		if(RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	//递归求左右部分最大值
	MaxLeftSum = MaxSubSum2(arr,left,center);
	MaxRightSum = MaxSubSum2(arr,center+1,right);

	//返回三者中的最大值
	return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
}

/*
将分支策略实现的算法封装起来
*/
int MaxSubSum2_1(int *arr,int len)
{
	return MaxSubSum2(arr,0,len-1);
}

/*
最优方法，时间复杂度O（n）
和最大的子序列的第一个元素肯定是正数
因为元素有正有负，因此子序列的最大和一定大于0
*/
int MaxSubSum3(int *arr,int len)
{
	int i;
	int MaxSum = 0;
	int CurSum = 0;
	for(i=0;i<len;i++)
	{
		CurSum += arr[i];
		if(CurSum > MaxSum)
			MaxSum = CurSum;
		//如果累加和出现小于0的情况，
		//则和最大的子序列肯定不可能包含前面的元素，
		//这时将累加和置0，从下个元素重新开始累加
		if(CurSum < 0)
			CurSum = 0;
	}
	return MaxSum;
}


int main()
{
	int arr[] = {2,4,-7,5,2,-1,2,-4,3};
	printf("子序列的最大和为：%d\n",MaxSubSum2_1(arr,9));
	return 0;
}