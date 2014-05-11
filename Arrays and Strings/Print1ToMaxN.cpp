#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*
打印字符数表示的数字，要跳过前面的'0'
*/
void PrintNum(char *num)
{
	int i = 0;
	while(num[i] == '0')
		i++;
	puts(num+i);
}

/*
字符串表示的数字模拟自加1
*/
bool Increment(char *num)
{
	bool isOverflow = false;
	int len = strlen(num);
	int i;

	//字符转化为整数
	for(i=0;i<len;i++)
		num[i] = num[i] - '0';

	//计算加1的结果
	num[len-1]++;
	for(i=len-1;i>=0;i--)
	{
		if(num[i]>=10)
		{	
			if(i == 0)
			{	//如果在最高位进位，则说明打印完了
				isOverflow = true;
				num[i]--;
			}
			else
			{
				num[i] -= 10;
				num[i-1] += 1;
			}
		}
		else
			break;
	}

	//整数转化为字符
	for(i=0;i<len;i++)
		num[i] = num[i] + '0';	

	return isOverflow;

}

/*
打印从1到最大的n位数
*/
void PrintToMaxN(int n)
{
	if(n<=0)
		return;

	char *num = (char *)malloc((n+1)*sizeof(char));
	if(num == NULL)
		exit(EXIT_FAILURE);
	//每个字节都初始化为'0'字符
	memset(num,'0',n*sizeof(char));
	num[n] = '\0';
	while(!Increment(num))
		PrintNum(num);

	free(num);
	num = NULL;
}

int main()
{
	int n;
	scanf("%d",&n);
	PrintToMaxN(n);
	return 0;
}