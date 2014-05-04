#include<stdio.h>
#include<stdbool.h>
/*
在m*n的升序二维数组matrix中查找是否有key
*/
bool Find(int *matrix,int m,int n,int key)
{
	if(matrix==NULL || m<1 || n<1)
		return false;
	int row = 0;
	int col = n-1;
	while(row<=m-1 && col>=0)
	{
		if(matrix[row*n+col] == key)
			return true;
		else if(matrix[row*n+col] > key)
			col--;
		else
			row++;
	}
	return false;
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF)
	{
		int key,i;
		//不加static会产生栈内存溢出，
		//如果不加static，matrix数组的内存在栈内分配，
		//如果加static，matrix数组的内存分配在全局已初始化区。
		//另外，此处用最大范围的数组，会增大所用内存，
		//但如果用malloc动态分配，则会增加运行时间。
		static int matrix[1000*1000] = {0};
		scanf("%d",&key);
		for(i=0;i<m*n;i++)
			scanf("%d",matrix+i);
		bool result = Find(matrix,m,n,key);
		if(result)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}