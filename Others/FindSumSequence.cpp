#include<stdio.h>
#include<stdbool.h>
bool can;

/*
void PrintSequence(int start ,int end)
{
	int i;
	for(i=start;i<=end;i++)
	{
		printf("%d",i);
		if(i == end)
			printf("\n");
		else
			printf(" ");
	}
}
*/

/*
找到和为s的连续正数序列
*/
void FindSumSequence(int s)
{
	int start = 1;
	int end = 2;
	int mid = (1+s)>>1;
	int cursum = start + end;

	while(start < mid)
	{
		if(cursum == s)
		{	can = true;
		//	PrintSequence(start,end);
			int i;
			for(i=start;i<=end;i++)
			{
				printf("%d",i);
				if(i == end)
					printf("\n");
				else
					printf(" ");
			}
			end++;
			cursum += end;
		}
		else if(cursum < s)
		{
			end++;
			cursum += end;
		}
		else
		{
			cursum -= start;
			start++;
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