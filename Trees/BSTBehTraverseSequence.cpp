#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool IsBehSequenceBST(int *seq,int len)
{
	if(seq==NULL || len<1)
		return false;

	int root = seq[len-1];
	int i;
	for(i=0;i<len-1;i++)
		if(seq[i]>root)
			break;

	//第一个右子树元素的下标
	int RightStart = i;

	for(;i<len-1;i++)
		if(seq[i]<root)
			return false;
 
	bool left = true;
	if(RightStart > 0)
		left = IsBehSequenceBST(seq,RightStart);
	bool right = true;
	if(RightStart < len-1-RightStart)
		right = IsBehSequenceBST(seq+i,len-RightStart-1);

	return (left && right);

}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int *seq = (int *)malloc(n*sizeof(int));
		if(seq == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",seq+i);
		if(IsBehSequenceBST(seq,n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}