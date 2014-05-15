#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode
{
	int data;
	int rchild;
	int lchild;
}BTNode;


/*
判断pTree1是否包含pTree2
*/
void MirrorTree(BTNode *pTree,int index)
{
	if(pTree == NULL)
		return;
	if(index == -1)
		return;
	if(pTree[index].lchild==-1 && pTree[index].rchild==-1)
		return;

	int temp = pTree[index].lchild;
	pTree[index].lchild = pTree[index].rchild;
	pTree[index].rchild = temp;

	if(pTree[index].lchild!=-1)
		MirrorTree(pTree,pTree[index].lchild);
	if(pTree[index].rchild!=-1)
		MirrorTree(pTree,pTree[index].rchild);
}

//这里设置全局变量i的目的是为了将先序遍历到的元素依次保存到数组preTraverse中，
//其目的是为了确定最后一个输出元素，这样好调整输出的格式，使输出符合测试系统的要求。
int i = 0;
void pre_traverse(BTNode *pTree,int index,int *preTraverse,int n)
{
	if(pTree == NULL)
		return;
	if(index != -1 && i<n)
	{
		preTraverse[i++] = pTree[index].data;
		if(pTree[index].lchild != -1)
			pre_traverse(pTree,pTree[index].lchild,preTraverse,n);
		if(pTree[index].rchild != -1)
			pre_traverse(pTree,pTree[index].rchild,preTraverse,n);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		//输入树pTree各节点的值
		BTNode *pTree = NULL;
		if(n>0)
		{
			pTree = (BTNode *)malloc(n*sizeof(BTNode));
			if(pTree == NULL)
				exit(EXIT_FAILURE);
			int i,data;
			//输入n个节点的data
			for(i=0;i<n;i++)
			{
				scanf("%d",&data);
				pTree[i].data = data;
				pTree[i].rchild = -1;
				pTree[i].lchild = -1;
			}

			//输入n行节点连接关系
			for(i=0;i<n;i++)
			{
				char ci;
				//这两行的作用是为了跳过缓冲区中的换行符
				//这里不能用fflush(stdin)，gcc不支持，这只是一些编译器自加的，
				//如果用了，测试系统会报RE。
				while(getchar() != '\n')
					continue;
				scanf("%c",&ci);
				if(ci == 'z')
					continue;
				else if(ci == 'l')
				{
					int lindex;
					scanf("%d",&lindex);
					pTree[i].lchild = lindex-1;
				}
				else if(ci == 'r')
				{
					int rindex;
					scanf("%d",&rindex);
					pTree[i].rchild = rindex-1;
				}
				else if(ci == 'd')
				{
					int lindex,rindex;
					scanf("%d",&lindex);
					scanf("%d",&rindex);
					pTree[i].lchild = lindex-1;
					pTree[i].rchild = rindex-1;
				}
			}
		}
		
		if(n == 0)
		{
			printf("NULL\n");
			continue;
		}
		MirrorTree(pTree,0);
		//先将遍历的元素依次保存到preTraverse数组中
		int *preTraverse = (int *)malloc(n*sizeof(int));
		if(preTraverse == NULL)
			exit(EXIT_FAILURE);
		pre_traverse(pTree,0,preTraverse,n);
		int i;
		for(i=0;i<n;i++)
		{
			//是输出符合测试系统要求的格式
			if(i == n-1)
				printf("%d\n",preTraverse[i]);
			else
				printf("%d ",preTraverse[i]);	
		}

		free(preTraverse);
		preTraverse = NULL;

		free(pTree);
		pTree = NULL;
	}
	return 0;
}
