/*
员工年龄排序，主要用计数排序的思想,
时间复杂度为O(n)，需要固定大小的额外辅助空间
*/
#include<stdio.h>
#include<string.h>

/*
计数排序，员工年龄肯定在0-99之间
*/
void SortAge(int ages[],int len)
{
	if(ages == NULL || len<1)
		return ;
	int timesOfAge[100];
	memset(timesOfAge,0,sizeof(timesOfAge));
	int i;
	//计算每个年龄员工的个数
	for(i=0;i<len;i++)
	{
		if(ages[i]<=99 && ages[i]>=0)
			timesOfAge[ages[i]]++;
	}
	//对ages进行排序
	int index = 0;
	for(i=0;i<100;i++)
	{
		int j = 0;
		while(j<timesOfAge[i])
		{
			ages[index++] = i;
			j++;
		}
	}
} 

int main()
{
	int ages[] = {33,34,45,24,36,23,21,22,19,26,45,34,21,34,34,33,52,22,32,25,27,43,22,21,20,33,26,27,15,29};
	int len = 30;
	SortAge(ages,len);
	int i;
	for(i=0;i<len;i++)
		printf("%d ",ages[i]);
	printf("\n");
	return 0;
}