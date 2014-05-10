#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool flag = true;

//求base的正数absExp次幂
double PowerAbs(double base,unsigned int absExp)
{
	//递归退出的条件
	if(absExp == 0)
		return 1.0;
	if(absExp == 1)
		return base;
	
	//递归求次方
	double result = PowerAbs(base,absExp>>1);
		result *= result;
	//判断奇偶性
	if(absExp&1 == 1)
		result *= base;

	return result; 
}

//求base的exp次方
double Power(double base,int exp)
{
	//底数为0，指数为负数的情况
	if(fabs(base-0.0)<0.0000001 && exp<=0)
	{
		flag = false;
		return 0.0;
	}

	unsigned int absExp = (unsigned int)abs(exp);
	double result = PowerAbs(base,absExp);
	if(exp<0)
		result = 1.0/result;

	return result;
}

int main()
{
	int n,exp;
	double base;
	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			//每次都要先将flag置为true
			flag = true;
			scanf("%lf %d",&base,&exp);
			double result = Power(base,exp);
			if(flag)
				printf("%.2ef\n",result);
			else
				printf("INF\n");
		}
	}
	return 0;
}