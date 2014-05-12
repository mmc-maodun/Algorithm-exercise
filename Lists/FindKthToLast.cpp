/***************************************************
题目描述：
找到单链表中倒数第n个元素
****************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

/*
找到单链表中倒数第k个元素
*/
PNODE FindKthToLast(PNODE pHead,unsigned int k)
{ 
	if(pHead==NULL || k<1)
		return NULL;
	PNODE p1 = pHead;
	PNODE p2 = pHead;
	while(p2!=NULL && k>0)
	{
		p2 = p2->pNext;
		k--;
	}
	if(k>0)
		return NULL;
	while(p2 != NULL)
	{
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	return p1;
}

int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k) != EOF)
	{
		int i,data;
		scanf("%d",&data);
		PNODE pHead =(PNODE)malloc(sizeof(NODE));
		if(pHead == NULL)
			exit(EXIT_FAILURE);
		pHead->data = data;
		pHead->pNext = NULL;

		PNODE pCur = pHead;
		for(i=0;i<n-1;i++)
		{
			scanf("%d",&data);
			PNODE pNew =(PNODE)malloc(sizeof(NODE));
			if(pNew == NULL)
				exit(EXIT_FAILURE);
			pNew->data = data;
			pNew->pNext = NULL;
			pCur->pNext = pNew;
			pCur = pCur->pNext;
		}

		PNODE pFind = FindKthToLast(pHead,k);
		if(pFind == NULL)
			printf("NULL\n");
		else
			printf("%d\n",pFind->data);
	}
	return 0;
}



