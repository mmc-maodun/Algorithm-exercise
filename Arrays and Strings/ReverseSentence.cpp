#include<stdio.h>

void Swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/*
反转字符串
*/
void Reverse(char *str,char *begin,char *end)
{
	if(str==NULL || begin==NULL || end==NULL)
		return;

	while(begin < end)
	{
		Swap(begin,end);
		begin++;
		end--;
	}
}

/*
反转单词顺序
*/
void ReverseSentence(char *str)
{
	if(str == NULL)
		return;

	char *begin = str;
	char *end = str;
	while(*end != '\0')
		end++;
	end--;
	//反转整个字符串
	Reverse(str,begin,end);

	//反转每个单词
	begin = str;
	while(*begin == ' ')
		begin++;
	end = begin;
	while(*begin != '\0')
	{
		while(*end!=' ' && *end!='\0')
			end++;
		end--;
		Reverse(str,begin,end);

		//跳过多个空格
		end++;
		while(*end == ' ')
			end++;
		begin = end;
	}
}

int main()
{
	char str[50000];
	while(gets(str) != NULL)
	{
		ReverseSentence(str);
		puts(str);
	}
	return 0;
}