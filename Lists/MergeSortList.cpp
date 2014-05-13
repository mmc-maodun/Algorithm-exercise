#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*pNode;

/*
合并两个升序链表，合并后的链表依然升序排列
*/
pNode MergeList(pNode pHead1,pNode pHead2)
{
	if(pHead1 == NULL)
		return pHead2;
	if(pHead2 == NULL)
		return pHead1;

	pNode pMergeHead = NULL;
	if(pHead1->data > pHead2->data)
	{
		pMergeHead = pHead2;
		pMergeHead->next = MergeList(pHead1,pHead2->next);
	}
	else
	{
		pMergeHead = pHead1;
		pMergeHead->next = MergeList(pHead2,pHead1->next);
	}
	return pMergeHead;
}

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		pNode pHead1 = NULL;
		if(n > 0)
		{
			int i,data;
			scanf("%d",&data);
			pHead1 =(pNode)malloc(sizeof(Node));
			if(pHead1 == NULL)
				exit(EXIT_FAILURE);
			pHead1->data = data;
			pHead1->next = NULL;

			pNode pCur = pHead1;
			for(i=0;i<n-1;i++)
			{
				scanf("%d",&data);
				pNode pNew =(pNode)malloc(sizeof(Node));
				if(pNew == NULL)
					exit(EXIT_FAILURE);
				pNew->data = data;
				pNew->next = NULL;
				pCur->next = pNew;
				pCur = pCur->next;
			}
		}

		pNode pHead2 = NULL;
		if(m > 0)
		{
			int i,data;
			scanf("%d",&data);
			pHead2 =(pNode)malloc(sizeof(Node));
			if(pHead2 == NULL)
				exit(EXIT_FAILURE);
			pHead2->data = data;
			pHead2->next = NULL;

			pNode pCur = pHead2;
			for(i=0;i<m-1;i++)
			{
				scanf("%d",&data);
				pNode pNew =(pNode)malloc(sizeof(Node));
				if(pNew == NULL)
					exit(EXIT_FAILURE);
				pNew->data = data;
				pNew->next = NULL;
				pCur->next = pNew;
				pCur = pCur->next;
			}
		}

		pNode pMergeHead = MergeList(pHead1,pHead2);
		if(pMergeHead == NULL)
			printf("NULL\n");
		else
		{
			pNode pCur = pMergeHead;
			while(pCur != NULL)
			{
				//这里主要时要注意输出的格式
				if(pCur->next == NULL)
					printf("%d\n",pCur->data);
				else
					printf("%d ",pCur->data);
				pCur = pCur->next;
			}
		}
	}
	return 0;
}