#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*pNode;

/*
反转链表，返回翻转后的头结点
*/
pNode ReverseList(pNode pHead)
{
	if(pHead == NULL)
		return NULL;
	if(pHead->next == NULL)
		return pHead;

	pNode pCur = pHead;
	pNode pPre = NULL;
	while(pCur != NULL)
	{
		pNode pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	return pPre;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		pNode pHead = NULL;
		if(n > 0)
		{
			int i,data;
			scanf("%d",&data);
			pHead =(pNode)malloc(sizeof(Node));
			if(pHead == NULL)
				exit(EXIT_FAILURE);
			pHead->data = data;
			pHead->next = NULL;

			pNode pCur = pHead;
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

		pNode pNewHead = ReverseList(pHead);
		if(pNewHead == NULL)
			printf("NULL\n");
		else
		{
			pNode pCur = pNewHead;
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