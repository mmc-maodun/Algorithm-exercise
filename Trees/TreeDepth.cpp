#include<stdio.h>
#include<stdlib.h>


typedef struct BTNode
{
	int data;
	int rchild;
	int lchild;
}BTNode;

int max(int a,int b)
{
	return a>b ? a:b;
}

/*
求二叉树的深度
*/
int TreeDepth(BTNode *pTree,int index)
{
	if(pTree == NULL)
		return 0;

	if(index == -1)
		return 0;
	else
		return max(TreeDepth(pTree,pTree[index].lchild),TreeDepth(pTree,pTree[index].rchild)) + 1;
}


int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		BTNode *pTree = NULL;
		if(n>0)
		{
			pTree = (BTNode *)malloc(n*sizeof(BTNode));
			if(pTree == NULL)
				exit(EXIT_FAILURE);
			int i;
			//输入n个节点的data
			for(i=0;i<n;i++)
			{
				int data1,data2;
				scanf("%d %d",&data1,&data2);
				if(data1 != -1)
					pTree[i].lchild = data1-1;
				else
					pTree[i].lchild = -1;
				if(data2 != -1)
					pTree[i].rchild = data2-1;
				else
					pTree[i].rchild = -1;
			}
		}
		printf("%d",TreeDepth(pTree,0));
	}
	return 0;
}
