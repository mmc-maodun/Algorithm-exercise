#include<stdio.h>

/*
欧几里得算法，辗转相除求最大公约数
*/
int MaxYue1(int a,int b)
{
	//在辗转相除之前，确保a比b大
	if(a<b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	//辗转相除法球最大公约数
	while(b!=0)
	{
		int temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

/*
辗转相减法求最大公约数
*/
int MaxYue2(int a,int b)
{
	if(a<b)
		return MaxYue2(b,a);
	if(b==0)
		return a;
	else
		return MaxYue2(b,a-b);
}


/*
改进辗转相减法
*/
int MaxYue3(int a,int b)
{
	if(a<b)
		return MaxYue3(b,a);
	if(b==0)
		return a;
	else
	{
		if((a&1)==0)	//a为偶数
		{
			if((b&1)==0) //b也为偶数
				return (MaxYue3(a>>1,b>>1)<<1);
			else		//b为奇数
				return MaxYue3(a>>1,b);
		}
		else	//a为奇数
		{
			if((b&1)==0) //b为偶数
				return MaxYue3(a,b>>1);
			else		//b也为奇数
				return MaxYue3(b,a-b);
		}
	}
}


int main()
{
	int a = 10021000;
	int b = 1202000;
	printf("%d\n",MaxYue3(a,b));
	return 0;
}
