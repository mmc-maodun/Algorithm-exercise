#include<stdio.h>
#include<math.h>
#include<stdbool.h>
bool can;

/*
打印从Start开始的连续n个正数序列
*/
void PrintSequence(int start ,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",start+i);
		if(i == n-1)
			printf("\n");
		else
			printf(" ");
	}
}

/*
找到和为s的连续正数序列
*/
void FindSumSequence(int s)
{
	int i;
	//这里的i为要求的连续正数的个数，至少为2
	for(i=(int)sqrt(2*s);i>=2;i--)
	{
		if((2*s)%i == 0)
		{
			int DoubleStart = 2*s/i-i+1;
			if((DoubleStart&1) == 0)	//如果为偶数
			{
				can = true;
				PrintSequence(DoubleStart/2,i);
			}
		}
	}
}

int main()
{
	int s;
	while(scanf("%d",&s) != EOF && s>=0)
	{
		can = false;
		FindSumSequence(s);
		if(!can)
			printf("Pity!\n");
		printf("#\n");
	}
	return 0;
}