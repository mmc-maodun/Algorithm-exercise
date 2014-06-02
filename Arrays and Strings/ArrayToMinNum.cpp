#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strs[100][100000];

/*
自定义比较规则
*/
int mycompare(const void *str1,const void *str2)
{
	static char s1[20000000];
	static char s2[20000000];
	char *string1 = (char *)str1;
	char *string2 = (char *)str2;
	//将两个字符串合并在一起
	sprintf(s1,"%s%s",string1,string2);
	sprintf(s2,"%s%s",string2,string1);

	return strcmp(s1,s2);
}

/*
以字符串形式打印出最小的整数
*/
void PrintMinNum(int *nums,int len)
{
	if(nums==NULL || len<1)
		return;

	int i;
	//将整数写入到字符串中
	for(i=0;i<len;i++)
		sprintf(strs[i],"%d",nums[i]);

	//按照mycompare中指定的规则排序
	qsort(strs,len,100000*sizeof(char),mycompare);
	
	for(i=0;i<len;i++)
		printf("%s",strs[i]);
	printf("\n");
}


int main()
{
	int nums[100];
	int m;
	while(scanf("%d",&m) != EOF)
	{
		int i;
		for(i=0;i<m;i++)	
			scanf("%d",nums+i);

		PrintMinNum(nums,m);
	}

	return 0;
}
