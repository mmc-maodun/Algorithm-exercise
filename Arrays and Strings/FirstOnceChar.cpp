#include<stdio.h>
#include<string.h>

char FirstOnceChar(char *str)
{
	if(str == NULL)
		return '\0';

	int hashtable[256];
	memset(hashtable,0,sizeof(hashtable));
	char *pCur = str;
	while(*pCur != '\0')
		hashtable[(int)(*(pCur++))]++;

	while(*str != '\0')
	{
		if(hashtable[(int)(*str)] == 1)
			return *str;
		else
			str++;
	}
	return '\0';
}

int IndexOfFirstOnceChar(char *str)
{
	if(str == NULL)
		return -1;

	int len = strlen(str);
	int hashtable[256];
	memset(hashtable,0,sizeof(hashtable));
	int i;
	for(i=0;i<len;i++)
		hashtable[str[i]]++;

	for(i=0;i<len;i++)
		if(hashtable[str[i]] == 1)
			return i;
	return -1;
}

int main()
{
	char str[10010];
	while(gets(str) != NULL)
		printf("%d\n",IndexOfFirstOnceChar(str));
	return 0;
}