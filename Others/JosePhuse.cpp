#include<stdio.h>

typedef struct Node
{
	int next;	//下一个元素的编号
	int num;	//编号，从1开始
}Node;

Node arr[1000000];

int FindLastRemaining(int n,int m)
{
	if(n<1 || m<1)
		return 0;

	int start = 1;
	int current = start;
	int pre = current;
	while(start != arr[start].next)
	{
		//找到待删元素和它的前一个元素
		int i;
		for(i=0;i<m-1;i++)
		{
			pre = current;
			current = arr[current].next;
		}
		
		//删除元素，重新建立连接
		arr[pre].next = arr[current].next;
		start = arr[pre].next;
		current = start;
	}
	return arr[start].num;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF && n != 0)
	{
		int m;
		scanf("%d",&m);

		//将数据连成环
		int i;
		for(i=1;i<=n;i++)
		{
			arr[i].num = i;
			if(i == n)
				arr[i].next = 1;
			else
				arr[i].next = i+1;
		}

		printf("%d\n",FindLastRemaining(n,m));
	}
	return 0;
}
