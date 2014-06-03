#include <stdio.h>

/*
O(n)的方法
*/
int FactorialNum0_1(int n)
{
	int count = 0;
	int i;
	for(i=1;i<=n;i++)
	{
		int j = i;
		while(j%5 == 0)
		{
			count++;
			j /= 5;
		}
	}
	return count;
}

/*
O(log5n)的方法
*/
int FactorialNum0_2(int n)
{
	int count = 0;
	while(n)
	{
		count += n/5;
		n /= 5;
	}
	return count;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
		printf("%d\n",FactorialNum0_2(n));
	return 0;
}