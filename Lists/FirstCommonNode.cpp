#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*pNode;

/*
获取链表的长度
*/
int getLength(pNode pHead)
{
	int len = 0;
	pNode pCur = pHead;
	while(pCur != NULL)
	{
		len++;
		pCur = pCur->next;
	}
	return len;
}

/*
求两个链表的第一个公共节点
*/
pNode FindFirstCommonNode(pNode pHead1,pNode pHead2)
{
	if(pHead1==NULL ||pHead2==NULL)
		return NULL;

	int len1 = getLength(pHead1);
	int len2 = getLength(pHead2);
	pNode pListLong = pHead1;
	pNode pListShort = pHead2;
	int distance = len1-len2;
	int shortLength = len2;
	if(len1 < len2)
	{
		pListLong = pHead2;
		pListShort = pHead1;
		distance = len2-len1;
		shortLength = len1;
	}
	
	int i;
	for(i=0;i<distance;i++)
		pListLong = pListLong->next;
	for(i=0;i<shortLength;i++)
	{
		if(pListLong->data == pListShort->data)
			break;
		pListLong = pListLong->next;
		pListShort = pListShort->next;
	}
	return pListLong;
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF)
	{
		pNode pHead1 = NULL;
		if(m>0)
		{
			int data;
			scanf("%d",&data);
			pHead1 = (pNode)malloc(m*sizeof(Node));
			if(pHead1 == NULL)
				exit(EXIT_FAILURE);
			pHead1->data = data;
			pHead1->next = NULL;

			pNode pCur = pHead1;
			int i;
			for(i=0;i<m-1;i++)
			{
				scanf("%d",&data);
				pNode pNew = (pNode)malloc(sizeof(Node));
				if(pNew == NULL)
					exit(EXIT_FAILURE);
				pNew->data = data;
				pNew->next = NULL;
				pCur->next = pNew;
				pCur = pCur->next;
			}
		}

		pNode pHead2 = NULL;
		if(n>0)
		{
			int data;
			scanf("%d",&data);
			pHead2 = (pNode)malloc(n*sizeof(Node));
			if(pHead2 == NULL)
				exit(EXIT_FAILURE);
			pHead2->data = data;
			pHead2->next = NULL;

			pNode pCur = pHead2;
			int i;
			for(i=0;i<n-1;i++)
			{
				scanf("%d",&data);
				pNode pNew = (pNode)malloc(sizeof(Node));
				if(pNew == NULL)
					exit(EXIT_FAILURE);
				pNew->data = data;
				pNew->next = NULL;
				pCur->next = pNew;
				pCur = pCur->next;
			}
		}

		pNode pResult = FindFirstCommonNode(pHead1,pHead2);
		if(pResult != NULL)
			printf("%d\n",pResult->data);
		else
			printf("My God\n");
	}
	return 0;
}