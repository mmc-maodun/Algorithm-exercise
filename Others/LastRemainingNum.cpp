#include<stdio.h>

int LastRemaining(int n,int m)
{
	if(n<1 || m<1)
		return 0;

	int last = 0;
	int i;
	for(i=2;i<=n;i++)
		last = (last + m)%i;
	return last;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF && n != 0)
	{
		int m;
		scanf("%d",&m);
		printf("%d\n",LastRemaining(n,m)+1);
	}
	return 0;
}
