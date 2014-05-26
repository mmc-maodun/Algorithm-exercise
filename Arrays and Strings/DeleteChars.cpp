#include<stdio.h>
#include<string.h>
#define MAX 256

void DeleteChars(char *str1,char *str2)
{
	if(str1==NULL || str2==NULL)
		return;

	bool hashtable[MAX];
	memset(hashtable,0,sizeof(hashtable));

	//将str2中字符对应的hashtable数组中的位置上的值设为ture
	while(*str2 != '\0')
	{
		//ASCII值在128-255之间的的字符，
		//用char保存，转化为int型,在-128--1之间
		int index;
		if(*str2 >= 0)
			index = *str2;
		else
			index = *str2 + 256;

		hashtable[index] = true;
		++str2;
	}

	char *pFast = str1;
	char *pSlow = str1;
	while(*pFast != '\0')
	{
		int index;
		if(*pFast >= 0)
			index = *pFast;
		else
			index = *pFast + 256;

		//无论是否碰到要删除的字符，pFast都后移，
		//只有没碰到要删除的字符时，pSlow才后移
		if(!hashtable[index])
			*pSlow++ = *pFast;	
		++pFast;
	}
	*pSlow = '\0';
}

int main()
{

	char str1[] = "They are students";
	char str2[] = "Tt";
	DeleteChars(str1,str2);
	puts(str1);
	return 0;
}