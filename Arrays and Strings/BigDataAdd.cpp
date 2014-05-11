/******************
字符串实现大数相加
Author:兰亭风雨
Date:2014-05-11
******************/
#include<stdio.h>
#include<string.h>

#define MAX 100

char *BigDataAdd(char *s1,char *s2)
{
	if(s1==NULL || s2==NULL)
		return NULL;

	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int Maxlen = (len1>len2)?len1:len2;
	
	//将对应的字符转化为整数，并使二者对齐到Maxlen处，
	//前面的字符通过memset用ASCII值为0的字符替换，
	//最高位留出来，如果次高位发生进位，则可以保存进位1，
	//这里s1和s2相当于变为了整数数组，由于字符的ASCII值在0-255之间，
	//因此这里不用开辟int数组，直接用自身的char数组即可
	int i,k;
	for(i=len1-1,k=Maxlen;i>=0;i--,k--)
		s1[k] = s1[i] - '0';
	if(k>=0)
		memset(s1,0,(k+1)*sizeof(char));
	for(i=len2-1,k=Maxlen;i>=0;i--,k--)
		s2[k] = s2[i] - '0';
	if(k>=0)
		memset(s2,0,(k+1)*sizeof(char));

	//整数数组相加到s1中
	for(i=Maxlen;i>=1;i--)
	{
		s1[i] += s2[i];
		if(s1[i]>=10)
		{
			s1[i] -= 10;
			s1[i-1] += 1;
		}
	}
	
	//将s1转换为为相加后的字符串
	if(s1[0] == 0)
	{	//如果次高位没有进位
		for(i=1;i<=Maxlen;i++)
			s1[i-1] = s1[i] +'0';
		s1[i-1] = '\0';
	}
	else
	{	//如果次高位有进位
		for(i=0;i<=Maxlen;i++)
			s1[i] = s1[i] +'0';
		s1[i] = '\0';
	}
	return s1;
}

int main()
{
	char s1[MAX];
	char s2[MAX];
	gets(s1);
	gets(s2);
	char *result = BigDataAdd(s1,s2);
	if(result != NULL)
		puts(result);
	else
		printf("Wrong\n");
	return 0;
}