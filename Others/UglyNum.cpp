#include<stdio.h>
#include<stdlib.h>

int UglyNums[1500];

int Min(int a,int b,int c)
{
	int min =(a<b)?a:b;
	min = (min<c)?min:c;
	return min;
}

int GetUglyNum(int index)
{
	if(index <= 0)
		return 0;

	UglyNums[0] = 1;
	int CurrentIndex= 1;	//当前要求的丑数的下标索引
	int *p2 = UglyNums;
	int *p3 = UglyNums;
	int *p5 = UglyNums;

	//求每个丑数，并保存起来
	while(CurrentIndex < index)
	{
		int min = Min(2*(*p2),3*(*p3),5*(*p5));
		UglyNums[CurrentIndex] = min;
		
		//每次循环都从上次的p2,p3和p5的下一个位置开始
		while(2*(*p2) <= UglyNums[CurrentIndex])
			++p2;
		while(3*(*p3) <= UglyNums[CurrentIndex])
			++p3;
		while(5*(*p5) <= UglyNums[CurrentIndex])
			++p5;

		++CurrentIndex;
	}

	int result = UglyNums[index-1];
	return result;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
		printf("%d\n",GetUglyNum(n));
	return 0;	
}
