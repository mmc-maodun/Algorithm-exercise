#include<stdio.h>

/*
分别统计num各位上1出现的次数，
相加得到1出现的总次数
*/
long long CountNum1(long long num)
{
	if(num <= 0)
		return 0;

	long long count = 0;	//统计1出现的次数
	long long current;    //当前位
	long long base = 1;	//当前位的基
	long long remain = 0;	//当前位为1时，后面位剩余的数（即不完整的部分）中1出现的次数
	while(num)
	{
		current = num%10;
		num = num/10;

		if(current > 1)
			 count += (num+1)*base;
		else if(current == 1)
			count += num*base + (remain+1);
		else
			count += num*base;
	
		//下一位要用到的基和剩余不完整部分值
		remain += current*base; 
		base *= 10;
	}

	return count;
}

int main()
{
	long long a,b;
	//a,b的大小不定
	while(scanf("%lld %lld",&a,&b) != EOF)
	{
		long long result;
		if(a > b)
			result = CountNum1(a) - CountNum1(b-1);
		else
			result = CountNum1(b) - CountNum1(a-1);

		printf("%lld\n",result);
	}
	return 0;
}