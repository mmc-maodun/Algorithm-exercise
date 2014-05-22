#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode
{
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
}BSTNode,*BSTree;

/*
根据题目要求的格式创建二叉排序树
*/
void CreateBST(BSTree *pRoot)
{
	int data;
	scanf("%d",&data);
	if(data == 0)
		pRoot = NULL;
	else
	{
		*pRoot = (BSTree)malloc(sizeof(BSTNode));
		if(*pRoot == NULL)
			exit(EXIT_FAILURE);
		(*pRoot)->data = data;
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
		CreateBST(&((*pRoot)->left));
		CreateBST(&((*pRoot)->right));
	}
}

/*
采用中序遍历的方式将二叉树转化为双向链表，
*pLas指向双向链表的最后一个节点
*/
void ConvertNode(BSTree pRoot,BSTree *pLast)
{
	if(pRoot == NULL)
		return;
	
	//先转化左子树
	if(pRoot->left != NULL)
		ConvertNode(pRoot->left,pLast);

	//将双向链表的最后一个节点与根节点连接在一起
	pRoot->left = *pLast;
	if(*pLast != NULL)
		(*pLast)->right = pRoot;
	*pLast = pRoot;

	//转换右子树
	if(pRoot->right != NULL)
		ConvertNode(pRoot->right,pLast);
}

/*
返回双向链表的头结点
*/
BSTree Convert(BSTree pRoot)
{
	if(pRoot == NULL)
		return NULL;
	if(pRoot->left==NULL && pRoot->right==NULL)
		return pRoot;

	BSTree pLast = NULL;
	ConvertNode(pRoot,&pLast);
	
	//返回头结点
	BSTree pHead = pLast;
	while(pHead->left != NULL)
		pHead = pHead->left;

	return pHead;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			BSTree pRoot = NULL;
			CreateBST(&pRoot);
			BSTree pHead = Convert(pRoot);
			while(pHead != NULL)
			{
				printf("%d ",pHead->data);
				pHead = pHead->right;
			}

			printf("\n");
			free(pRoot);
			pRoot = NULL;
		}
	}
	return 0;
}