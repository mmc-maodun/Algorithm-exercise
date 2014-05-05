#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*pNode;

/*
递归从尾到头打印单链表
*/
void PrintListReverse(pNode pHead)
{
	if(pHead == NULL)
		return;
	if(pHead->next != NULL)
		PrintListReverse(pHead->next);
	printf("%d\n",pHead->data);
}

pNode CreateList()
{
	ElemType val;
	pNode pHead = NULL;
	pNode pCur = NULL;
	do
	{
		scanf("%d",&val);
		if(val != -1)
		{
			pNode pNew = (pNode)malloc(sizeof(Node));
			if(pNew == NULL)
				exit(EXIT_FAILURE);
			pNew->data = val;
			pNew->next = NULL;

			if(pHead == NULL)
			{
				pHead = pNew;
				pCur = pHead;
			}
			else
			{
				pCur->next = pNew;
				pCur = pCur->next;
			}
		}
	}while(val != -1);

	return pHead;
}

void DestroyList(pNode pHead)
{
	if(pHead == NULL)
		return;
	pNode p = NULL;
	while(pHead != NULL)
	{
		p = pHead->next;
		free(pHead);
		pHead = p;
	}
}
int main()
{
	pNode pHead = CreateList();
	PrintListReverse(pHead);
	DestroyList(pHead);
	return 0;
}