#include<stdio.h>

int AddNumThoughBit(int a,int b)
{
	int sum; //不含进位的和
	int add1; //进位

	while(b != 0)
	{
		sum = a^b;
		add1 = (a&b)<<1;
		a = sum;
		b = add1;
	}
	return a;
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF)
		printf("%d\n",AddNumThoughBit(m,n));
}