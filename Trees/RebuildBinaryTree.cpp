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

bool CanReBuild;	//������ʾ�Ƿ��ܹ��ع�������

/*
preΪǰ���������飬invΪ�����������飬lenΪ���鳤�ȣ��ع�������*ppTree
*/
void RebuildBinaryTree(BTree *ppTree,int *pre,int *inv,int len)
{
	if(pre==NULL || inv==NULL)
	{
		CanReBuild = false;
		return ;
	}
	//�ô���Ϊ�ݹ��ĳ��ڣ����ܽ�CanReBuild��Ϊfalse����������Զ����No
	//���⣬Ҳ���Խ��˴����ж�ȥ�������ں��������ݹ鴦���϶Գ���i��len-i-1�Ƿ�����0���ж�
	if(len < 1)
		return ;

	//��inv�������ҳ���pre[0]���ȵ�Ԫ�أ��Ӷ�ȷ�����������ķ�Χ
	int i;
	for(i=0;i<len;i++)
		if(pre[0] == inv[i])
			break;
	//��������inv������û���ҵ���pre[0]���ȵ�ֵ���������ع�������
	if(i >= len)
	{
		CanReBuild = false;
		return ;
	}

	//����ÿ�������ĸ��ڵ�
	*ppTree = (BTree)malloc(sizeof(BTNode));
	if(*ppTree == NULL)
		exit(EXIT_FAILURE);
	(*ppTree)->data = pre[0];
	(*ppTree)->left = NULL;	
	(*ppTree)->right = NULL;

	//�ݹ鹹��ÿ�����ڵ�����������
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
