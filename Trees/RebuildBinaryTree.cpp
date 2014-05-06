#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef struct BTNode 
{
	ElemType data;
	struct BTNode *left;
	struct BTNode *right;
}BTNode,*BTree;

bool CanReBuild;	//用来标示是否能够重构二叉树

/*
pre为前序遍历数组，inv为中序遍历数组，len为数组长度，重构二叉树*ppTree
*/
void RebuildBinaryTree(BTree *ppTree,int *pre,int *inv,int len)
{
	if(pre==NULL || inv==NULL)
	{
		CanReBuild = false;
		return ;
	}
	//该处作为递归的出口，不能将CanReBuild置为false，否则会永远输出No
	//另外，也可以将此处的判断去掉，而在后面两个递归处加上对长度i和len-i-1是否大于0的判断
	if(len < 1)
		return ;

	//在inv数组中找出与pre[0]相等的元素，从而确定左右子树的范围
	int i;
	for(i=0;i<len;i++)
		if(pre[0] == inv[i])
			break;
	//如果遍历inv结束都没有找到与pre[0]相等的值，则不能重构二叉树
	if(i >= len)
	{
		CanReBuild = false;
		return ;
	}

	//构建每个子树的根节点
	*ppTree = (BTree)malloc(sizeof(BTNode));
	if(*ppTree == NULL)
		exit(EXIT_FAILURE);
	(*ppTree)->data = pre[0];
	(*ppTree)->left = NULL;	
	(*ppTree)->right = NULL;

	//递归构建每个根节点的左右子树
	RebuildBinaryTree(&(*ppTree)->left,pre+1,inv,i);
	RebuildBinaryTree(&(*ppTree)->right,pre+i+1,inv+i+1,len-i-1);	
}

void BehTraverse(BTree pTree)
{
	if(pTree != NULL)
	{
		if(pTree->left != NULL)
			BehTraverse(pTree->left);
		if(pTree->right != NULL)
			BehTraverse(pTree->right);
		printf("%d ",pTree->data);
	}
}

void DestroyTree(BTree pTree)
{
	if(pTree)
	{
		if(pTree->left)
			DestroyTree(pTree->left);
		if(pTree->right)
			DestroyTree(pTree->right);
		free(pTree);
		pTree = NULL;
	}
}
int main()
{
	int len;
	BTree pTree = NULL;
	while(scanf("%d",&len) != EOF)
	{
		int *pre = (int *)malloc(len*sizeof(int));
		int *inv = (int *)malloc(len*sizeof(int));
		if(pre == NULL || inv == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<len;i++)
			scanf("%d",pre+i);
		for(i=0;i<len;i++)
			scanf("%d",inv+i);

		CanReBuild = true;
		RebuildBinaryTree(&pTree,pre,inv,len);
		if(CanReBuild)
		{
			BehTraverse(pTree);
			printf("\n");
			DestroyTree(pTree);
		}
		else
			printf("No\n");

		free(pre);
		free(inv);
		pre = NULL;
		inv = NULL;
	}
	return 0;
}
