#include<stdio.h>

long long Fibonacci(unsigned int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	long long fib1 = 0;
	long long fib2 = 1;
	long long FibN = 0;
	unsigned int i;
	for(i=2;i<=n;i++)
	{
		FibN = fib1 + fib2;
		fib1 = fib2;
		fib2 = FibN;
	}
	return FibN;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
		printf("%lld\n",Fibonacci(n));
	return 0;
}