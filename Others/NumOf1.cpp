#include<stdio.h>
#include<stdlib.h>

int NumOf1(int n)
{
	int count = 0;
	while(n)
	{
		count++;
		n = n & (n-1);
	}
	return count;
}

int main()
{
	int nums;
	while(scanf("%d",&nums) != EOF)
	{
		int *N = (int *)malloc(nums*sizeof(int));
		if(N == NULL)
			exit(EXIT_FAILURE);
		int i;
		for(i=0;i<nums;i++)
		{
			scanf("%d",N+i);
			printf("%d\n",NumOf1(N[i]));
		}
	}

	return 0;
}