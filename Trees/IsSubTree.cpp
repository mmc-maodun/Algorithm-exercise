#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BTNode
{
	int data;
	int rchild;
	int lchild;
}BTNode;

/*
判断pTree2是否是与pTree1有共同的根节点的pTree1子树
*/
bool isSubTree(BTNode *pTree1,int index1,BTNode *pTree2,int index2)
{
	//前两个if语句不能颠倒，不然当pTree1和pTree2相同时，会误判为false
	if(index2 == -1)
		return true;
	if(index1 == -1)
		return false;
	if(pTree1[index1].data != pTree2[index2].data)
		return false;
	else
		return isSubTree(pTree1,pTree1[index1].lchild,pTree2,pTree2[index2].lchild) &&
			   isSubTree(pTree1,pTree1[index1].rchild,pTree2,pTree2[index2].rchild);
}

/*
判断pTree1是否包含pTree2
*/
bool isContainTree(BTNode *pTree1,int index1,BTNode *pTree2,int index2)
{
	if(pTree1==NULL || pTree2==NULL)
		return false;
	if(index1==-1 || index2==-1)
		return false;

	bool result = false;
	if(pTree1[index1].data == pTree2[index2].data)
		result = isSubTree(pTree1,index1,pTree2,index2);

	//如果pTree1[index1].lchild为-1，下次递归时会通过index1==-1的判断返回false，
	//因此这里不需要再加上pTree1[index1].lchild!=-1的判断条件
	if(!result)
		result = isContainTree(pTree1,pTree1[index1].lchild,pTree2,index2);
	if(!result)
		result = isContainTree(pTree1,pTree1[index1].rchild,pTree2,index2);

	return result;
}

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		//输入树pTree1各节点的值
		BTNode *pTree1 = NULL;
		if(n>0)
		{
			pTree1 = (BTNode *)malloc(n*sizeof(BTNode));
			if(pTree1 == NULL)
				exit(EXIT_FAILURE);
			int i,data;
			//输入n个节点的data
			for(i=0;i<n;i++)
			{
				scanf("%d",&data);
				pTree1[i].data = data;
				pTree1[i].rchild = -1;
				pTree1[i].lchild = -1;
			}

			//输入n行节点连接关系
			for(i=0;i<n;i++)
			{
				int ki;
				scanf("%d",&ki);
				if(ki == 0)
					continue;
				else if(ki == 1)
				{
					int lindex;
					scanf("%d",&lindex);
					pTree1[i].lchild = lindex-1;
				}
				else
				{
					int lindex,rindex;
					scanf("%d",&lindex);
					scanf("%d",&rindex);
					pTree1[i].lchild = lindex-1;
					pTree1[i].rchild = rindex-1;
				}
			}
		}

		//输入树pTree2各节点的值
		BTNode *pTree2 = NULL;
		if(m>0)
		{
			pTree2 = (BTNode *)malloc(m*sizeof(BTNode));
			if(pTree2 == NULL)
				exit(EXIT_FAILURE);
			int i,data;
			//输入n个节点的data
			for(i=0;i<m;i++)
			{
				scanf("%d",&data);
				pTree2[i].data = data;
				pTree2[i].rchild = -1;
				pTree2[i].lchild = -1;
			}

			//输入n行节点连接关系
			for(i=0;i<m;i++)
			{
				int ki;
				scanf("%d",&ki);
				if(ki == 0)
					continue;
				else if(ki == 1)
				{
					int lindex;
					scanf("%d",&lindex);
					pTree2[i].lchild = lindex-1;
				}
				else
				{
					int lindex,rindex;
					scanf("%d",&lindex);
					scanf("%d",&rindex);
					pTree2[i].lchild = lindex-1;
					pTree2[i].rchild = rindex-1;
				}
			}
		}

		if(isContainTree(pTree1,0,pTree2,0))
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
