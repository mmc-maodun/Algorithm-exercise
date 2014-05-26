#include<stdio.h>
#include<string.h>

/*
返回第一个出现一次的字符
*/
char FirstOnceChar(char *str)
{
	if(str == NULL)
		return '\0';

	int hashtable[256];
	memset(hashtable,0,sizeof(hashtable));
	char *pCur = str;
	while(*pCur != '\0')
	{
		if(*pCur<=127)
			hashtable[*(pCur++)]++;
		else
			hashtable[*(pCur++)+256]++;
	}

	while(*str != '\0')
	{
		int index;
		if(*str<=127)
			index = *str;
		else
			index = *str+256;

		if(hashtable[index] == 1)
			return *str;
		else
			str++;
	}
	return '\0';
}

/*
返回第一个出现一次的字符的下标
*/
int IndexOfFirstOnceChar(char *str)
{
	if(str == NULL)
		return -1;

	int len = strlen(str);
	int hashtable[256];
	memset(hashtable,0,sizeof(hashtable));
	int i;
	for(i=0;i<len;i++)
	{
		if(str[i]<=127)
			hashtable[str[i]]++;
		else
			hashtable[str[i]+256]++;
	}

	for(i=0;i<len;i++)
	{
		int index;
		if(str[i]<=127)
			index = str[i];
		else
			index = str[i]+256;

		if(hashtable[index] == 1)
			return i;
	}
	return -1;
}

int main()
{
	char str[10010];
	while(gets(str) != NULL)
		printf("%d\n",IndexOfFirstOnceChar(str));
	return 0;
}