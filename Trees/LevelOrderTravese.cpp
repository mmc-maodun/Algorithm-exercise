#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
二叉树的存储结构
*/
typedef struct BTNode
{
	int data;
	int rchild;
	int lchild;
}BTNode;

/*
队列的存储结构
*/
typedef struct Node
{
	BTNode data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Queue
{
	PNODE front;  //队头指针
	PNODE rear;   //队尾指针
}QUEUE,*PQUEUE;


/*
创建一个空队列，队头指针和队尾指针都指向头结点，
头结点中不存放数据，只存放指针
*/
PQUEUE create_queue()
{
	PQUEUE pS = (PQUEUE)malloc(sizeof(QUEUE));
	pS->front = (PNODE)malloc(sizeof(NODE));
	if(!pS || !pS->front)
	{
		printf("pS or front malloc failed!!");
		exit(-1);
	}
	else
	{
		pS->rear = pS->front;
		pS->front->pNext = NULL;
	}
	return pS;
}

/*
判断队列是否为空
*/
bool is_empty(PQUEUE pS)
{
	if(pS->front == pS->rear)
		return true;
	else
		return false;
}

/*
进队函数，从队尾进队，队头指针保持不变
*/
void en_queue(PQUEUE pS, BTNode e)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(!pNew)
	{
		printf("pNew malloc failed");
		exit(-1);
	}
	else
	{
		pNew->data = e;
		pNew->pNext = NULL;
		pS->rear->pNext = pNew;
		pS->rear = pNew;
	}
	return;
}

/*
出队函数，从队头出队，队尾指针保持不变，但当最后一个元素出队时，
需要对队尾指针重新赋值，使其指向头结点
*/
bool de_queue(PQUEUE pS,BTNode *pData)
{
	if(is_empty(pS))
		return false;
	else
	{
		PNODE p = pS->front->pNext;
		*pData = p->data;
		pS->front->pNext = p->pNext;

		//这里是队列头元素出队的特殊情况，一般情况下，删除队头元素时
		//仅需修改头结点中的指针，但当队列中最后一个元素被删除时，
		//队列尾指针也丢失了，因此需对队尾指针重新赋值（指向头结点）。
		if(pS->rear == p)         
			pS->rear = pS->front;
		free(p);
	}
	return true;
}

/*
销毁队列,头结点也被销毁,最后也将pS节点销毁，并将其指向为空，避免垂直指针的产生
*/
void destroy_queue(PQUEUE pS)
{
	if(is_empty(pS))
		return;
	else
	{
		while(pS->front)
		{
			pS->rear = pS->front->pNext;
			free(pS->front);
			pS->front = pS->rear;
		}
	}
	free(pS);
	pS = 0;
	return;
}

/*
层序遍历二叉树
*/
void LevelTraverse(BTNode *pTree,int index,int *LevTraverse,int n)
{
	if(pTree == NULL)
		return;
	if(index == -1)
		return;

	BTNode pBTNode;
	PQUEUE pS = create_queue();
	en_queue(pS, pTree[0]);
	int i = 0;
	while(!is_empty(pS) && i<n)
	{
		de_queue(pS,&pBTNode);
		//同样，先把元素按层序遍历的顺序保存起来
		LevTraverse[i++] = pBTNode.data;
		if(pBTNode.lchild != -1)
			en_queue(pS, pTree[pBTNode.lchild]);
		if(pBTNode.rchild != -1)
			en_queue(pS, pTree[pBTNode.rchild]);
	}

	destroy_queue(pS);
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
		
		
		//先将遍历的元素依次保存到preTraverse数组中
		int *LevTraverse = (int *)malloc(n*sizeof(int));
		if(LevTraverse == NULL)
			exit(EXIT_FAILURE);
		LevelTraverse(pTree,0,LevTraverse,n);
		int i;
		for(i=0;i<n;i++)
		{
			//使输出符合测试系统要求的格式
			if(i == n-1)
				printf("%d\n",LevTraverse[i]);
			else
				printf("%d ",LevTraverse[i]);	
		}

		free(LevTraverse);
		LevTraverse = NULL;

		free(pTree);
		pTree = NULL;
	}
	return 0;
}