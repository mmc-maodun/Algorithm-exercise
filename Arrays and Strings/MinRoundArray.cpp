#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int *A = (int *)malloc(n*sizeof(int));
		if(A == NULL)
			exit(EXIT_FAILURE);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",A+i);

		int p1 = 0;
		int p2 = n-1;
		int mid = p1;
		while(A[p1] >= A[p2])
		{
			if(p2-p1 == 1)
			{
				mid = p2;
				break;
			}
			mid = (p1+p2)/2;
			//特殊情况，只能顺序查找
			if(A[p1]==A[mid] && A[p2]==A[mid])
			{
				mid = p1;
				int i;
				for(i=p1+1;i<=p2;i++)
				{
					if(A[mid] > A[i])
						mid = i;
				}
				break;
			}
			if(A[mid]>=A[p1])
				p1 = mid;
			else if(A[mid]<=A[p2])
				p2 = mid;
		}
		printf("%d\n",A[mid]);
		free(A);
		A = 0;
	}
	return 0;
}