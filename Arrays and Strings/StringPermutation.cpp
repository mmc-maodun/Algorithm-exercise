#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char result[362900][10];
int count = 0; //排列字符串的个数

/*
交换两个字符
*/
void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/*
对字符串str从begin开始的后面的字符进行排列
*/
void Permutation(char *str,int begin)
{
	int len = strlen(str);
	if(begin == len-1)
	{
		strcpy(result[count++],str);
		return;
	}

	int i;
	for(i=begin;i<len;i++)
	{
		swap(&str[begin],&str[i]);
		Permutation(str,begin+1);
		swap(&str[begin],&str[i]);
	}
}

/*
将Permutation封装起来
*/
void PermutationAllChar(char *str)
{
	if(str == NULL)
		return ;
	Permutation(str,0);
}

/*
比较str1和str2的大小
*/
int myCompare(const void *a,const void *b)
{
	char *s1 = (char *)a;
	char *s2 = (char *)b;
	return strcmp(s1,s2);
}

int main()
{
	char str[10];
	while(gets(str))
	{
		PermutationAllChar(str);

		//快排对字符串数组进行字典排序
		//之前采用选择排序，并通过复制字符串排序，OJ上报超时
		//改用快排，AC。
		qsort(result,count,10*sizeof(char),myCompare);

		//跳过重复字符串
		int i;
		for(i=0;i<count;i++)
		{
			if(strcmp(result[i],result[i+1]) == 0)
				continue;
			puts(result[i]);
		}
 
		//下一个字符的排列依然从result数组的开始处开始存放
		count = 0;
	}
	return 0;
}