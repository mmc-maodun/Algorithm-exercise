#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

PSTACK create_stack();
void push_stack(PSTACK,int);
void traverse_stack(PSTACK);
bool pop_stack(PSTACK,int *);
bool is_empty(PSTACK);
void clear_stack(PSTACK);
void enter_Queue(PSTACK,int);
bool delete_Queue(PSTACK,PSTACK,int *);

int main()
{	
	int n;		//保存操纵的个数
	int data;	//保存输入的要push的元素
	int pData;	//保存pop出来的元素
	char *push = "PUSH";
	char *pop = "POP";
	char input[5];
	int data_pop;

	//创建两个空栈
	PSTACK pS1 = create_stack();
	PSTACK pS2 = create_stack();
	scanf("%d",&n);
	while(n-->0)
	{
		scanf("%s",input);
		if(strcmp(input,push) == 0)
		{
			scanf("%d",&data);
			enter_Queue(pS1,data);
		}
		if(strcmp(input,pop) == 0)
		{
			if(delete_Queue(pS1,pS2,&pData))
				printf("%d\n",pData);
			else
				printf("-1\n");
		}
	}

	clear_stack(pS1);
	clear_stack(pS2);
	return 0;
}

/*
创建一个空栈,并返回指向该栈的指针
*/
PSTACK create_stack()
{
	PSTACK pS = (PSTACK)malloc(sizeof(STACK));
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL==pS || NULL==pS->pTop)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pS->pBottom = pS->pTop;
	   pS->pBottom->pNext = NULL;
	}
	
	return pS;
}

/*
判断该栈是否为空
*/
bool is_empty(PSTACK pS)
{
	if(pS->pTop == pS->pBottom)
	   return true;
    else
	   return false;
}

/*
向pS指针指向的栈中压入数据val
*/
void push_stack(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pNew->data = val;
	   pNew->pNext = pS->pTop;
	   pS->pTop = pNew;
	}	
	return ;
}

/*
从栈中推出数据，并将推出的数据保存在pData指针所指向的位置
*/
bool pop_stack(PSTACK pS,int *pData)
{
	if(is_empty(pS))
	   return false;
	else
	{
	   PNODE p = pS->pTop;
	   *pData = p->data;
	   pS->pTop = p->pNext;
	   free(p);
	   p = NULL;
	   return true;
	}
}

/*
清空栈，即将其还原为空栈
*/
void clear_stack(PSTACK pS)
{
	if(is_empty(pS))
	   return ;
	else
	{
	   PNODE p = pS->pTop;
	   PNODE r = NULL;
	   while(p != pS->pBottom)
	   {
			r = p->pNext;
			free(p);
			p = r;
	   }
	   pS->pTop = pS->pBottom;
   	}
}

/*
用两个栈模拟入队
*/
void enter_Queue(PSTACK pS1,int val)
{
	push_stack(pS1,val);
}

/*
用两个栈模拟出队
*/
bool delete_Queue(PSTACK pS1,PSTACK pS2,int *pData)
{
	if(is_empty(pS1) && is_empty(pS2))
		return false;
	if(!is_empty(pS2))
		pop_stack(pS2,pData);
	else if(!is_empty(pS1))
	{
		while(!is_empty(pS1))
		{
			int pS1_popData;
			pop_stack(pS1,&pS1_popData);
			push_stack(pS2,pS1_popData);
		}
		pop_stack(pS2,pData);
	}
	return true;
}