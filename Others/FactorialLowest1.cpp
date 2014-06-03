#include<stdio.h>

int Lowest1(int n)
{
	int count = 0;
	while(n)
	{
		count += n/2;
		n /= 2;
	}
	return count + 1;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
		printf("%d\n",Lowest1(n));
	return 0;
}