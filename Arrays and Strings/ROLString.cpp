#include<stdio.h>
#include<string.h>

void Swap(char *a,char *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
翻转字符串中从start到end的这部分
*/
void ReverseString(char *str,int start,int end)
{
	while(start < end)
	{
		Swap(&str[start],&str[end]);
		start++;
		end--;
	}
}

/*
求左旋k位后得到的字符
*/
void ROLString(char *str,int k)
{
	if(str == NULL || k<=0)
		return;
	
	int len = strlen(str);
	//要考虑k大于len的情况
	k = k%len;
	if(k == 0)
		return;

	ReverseString(str,0,k-1);
	ReverseString(str,k,len-1);
	ReverseString(str,0,len-1);
}

int main()
{
	char str[1010];
	int k;
	while(scanf("%s %d",str,&k) != EOF)
	{
		ROLString(str,k);
		puts(str);
	}
	return 0;
}