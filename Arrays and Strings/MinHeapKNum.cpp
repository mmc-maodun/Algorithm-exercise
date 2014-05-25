#include<stdio.h>
#include<stdlib.h>

/*
arr[start+1...end]满足小顶堆的定义，
将arr[start]加入到小顶堆arr[start+1...end]中，
调整arr[start]的位置，使arr[start...end]也成为小顶堆
注：由于数组从0开始计算序号，也就是二叉堆的根节点序号为0，
因此序号为i的左右子节点的序号分别为2i+1和2i+2
*/
void HeapAdjustDown(int *arr,int start,int end)
{
	int temp = arr[start];	//保存当前节点
	int i = 2*start+1;		//该节点的左孩子在数组中的位置序号
	while(i<=end)
	{
		//找出左右孩子中最小的那个
		if(i+1<=end && arr[i+1]<arr[i])  
			i++;
		//如果符合堆的定义，则不用调整位置
		if(arr[i]>=temp)	
			break;
		//最小的子节点向上移动，替换掉其父节点
		arr[start] = arr[i];
		start = i;
		i = 2*start+1;
	}
	arr[start] = temp;
}

/*
得到最小的k个数，保存在arr中的最后面k个位置
*/
void MinHeapKNum(int *arr,int len,int k)
{
	if(arr==NULL || len<1 || k<1 || k>len)
		return;

	int i;
	//把数组建成为小顶堆
	//第一个非叶子节点的位置序号为(len-1)/2
	for(i=(len-1)/2;i>=0;i--)
		HeapAdjustDown(arr,i,len-1);
	//进行堆排序
	for(i=len-1;i>=len-k;i--)
	{
		//堆顶元素和最后一个元素交换位置，
		//这样最后的一个位置保存的是最小的数，
		//每次循环依次将次小的数值在放进其前面一个位置，
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//将arr[0...i-1]重新调整为小顶堆
		HeapAdjustDown(arr,0,i-1);
	}
}


int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k) != EOF)
	{
		int *A = (int *)malloc(sizeof(int)*n);
		if(A == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",A+i);

		MinHeapKNum(A,n,k);
		for(i=n-1;i>=n-k;i--)
		{
			//根据要求的格式输出
			if(i == n-k)
				printf("%d\n",A[i]);
			else
				printf("%d ",A[i]);
		}
	}
	return 0;
}