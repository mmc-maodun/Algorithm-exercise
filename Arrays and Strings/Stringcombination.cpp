#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
模拟二进制加1操作，当最高位要进位时，说明所有的位都是1，返回false，
用char数组来模拟比int数组更省空间，这里必须传入数组长度len，
由于我们CominationAll中将要传入的字符数组全部初始化为了'\0',
如果在该函数内部用strlen计算的话，会得到len=0。
*/
bool Increment(char *BindAdd,int len)
{
	if(BindAdd == NULL)
		return false;

	BindAdd[len-1]++;
	int i;
	for(i=len-1;i>=0;i--)
	{
		if(BindAdd[i] >= 2)
		{
			if(i == 0)
			{
				BindAdd[i]--;
				return false;
			}
			else
			{
				BindAdd[i] -= 2;
				BindAdd[i-1]++;
			}
		}
		else
			break;
	}
	return true;
}

/*
输出字符串的所有组合
*/
void CominationAll(char *str)
{
	if(str == NULL)
		return;

	int len = strlen(str);
	char *BindAdd = (char *)malloc(len*sizeof(char));
	if(BindAdd == NULL)
		exit(EXIT_FAILURE);

	memset(BindAdd,0,len*sizeof(char));
	while(Increment(BindAdd,len))
	{
		int i;
		for(i=0;i<len;i++)
		{
			if(BindAdd[i] == 1)
				putchar(str[i]);
		}
		putchar('\n');
	}

	free(BindAdd);
	BindAdd = NULL;
}

int main()
{
	char str[10];
	while(gets(str))
		CominationAll(str);
	return 0;
}