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
递归设置从index位往右的各位数字，并打印出来
*/
void RecursionPrint1ToN(char *num,int len,int index)
{
	if(index == len-1)
	{
		PrintNum(num);
		return;
	}
	int i;
	for(i=0;i<10;i++)
	{
		num[index+1] = i + '0';
		RecursionPrint1ToN(num,len,index+1);
	}
}

/*
打印从1到最大的n位数
*/
void Print1ToMaxN(int n)
{
	if(n<=0)
		return;

	char *num = (char *)malloc((n+1)*sizeof(char));
	if(num == NULL)
		exit(EXIT_FAILURE);
	//每个字节都初始化为'0'字符
	memset(num,'0',n*sizeof(char));
	num[n] = '\0';
	
	//全部打印出来
	int i;
	for(i=0;i<10;i++)
	{
		num[0] = i + '0';
		RecursionPrint1ToN(num,n,0);
	}

	free(num);
	num = NULL;
}

int main()
{
	int n;
	scanf("%d",&n);
	Print1ToMaxN(n);
	return 0;
}