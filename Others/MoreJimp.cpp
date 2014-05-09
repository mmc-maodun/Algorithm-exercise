#include<stdio.h>

long long Fibonacci(unsigned int n)
{
	if(n <= 0)
		return 0;
	if(n==1)
		return 1;
	long long FibN = 1;
	unsigned int i;
	for(i=2;i<=n;i++)
	{
		FibN *= 2;
	}
	return FibN;
}

int main()
{
	unsigned int n;
	while(scanf("%d",&n) != EOF)
		printf("%lld\n",Fibonacci(n));
	return 0;
}
