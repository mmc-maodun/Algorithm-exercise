#include<stdio.h>
#include<string.h>
#include<stdlib.h>;

char *ReplaceBlank(char *str)
{
	if(str == NULL)
		return NULL;
	int len = strlen(str);
	if(len == 0)
		return NULL;
	int i,count = 0;
	for(i=0;i<len;i++)
		if(str[i] == ' ')
			count++;
	//没有空格，就直接返回str
	if(count == 0)
		return str;
	int new_len = 2*count+len+1;
	char *dest = (char *)malloc(new_len*sizeof(char));
	if(dest == NULL)
		exit(EXIT_FAILURE);
	int j = 0;
	for(i=0;i<len;i++)
	{
		if(str[i] != ' ')
		{
			dest[j++] = str[i];
		}
		else
		{
			dest[j] = '%';
			dest[j+1] = '2';
			dest[j+2] = '0';
			j += 3;
		}
	}
	dest[j] = '\0';
	return dest;
}

int main()
{
	//虽然AC了（主要九度的测试用例没有大于这个范围的），但是人为地限制str的长度并不是最佳的方法，
	//最好使用C++中的string类或java中的String类，
	//但目前在C语言中，我还不知道怎么可以不限定长度地从键盘接受输入的字符串。
	static char str[10000000];
	gets(str);
	char *dest = ReplaceBlank(str);
	if(dest != NULL)
		puts(dest);
	return 0;
}
