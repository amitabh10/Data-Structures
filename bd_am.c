/*Write a Program to accept a graph from user and represent it with Adjacency Matrix and perform BFS and DFS traversals on it.*/

#include<stdio.h>
#include<stdlib.h>
int am[20][20]={0},v[20]={0};
int n,top=-1,stk[20];
int q[20],f=0,r=-1;
void recdfs(int i)
{
	int j;
	printf("v%d\n",i);
	v[i]=1;
	for(j=1;j<=n;j++)
	{
		if(am[i][j]==1 && v[j]!=1)
			recdfs(j);
	}
	printf("\n");		
}
int stkempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(int e)
{
	if(top==19)
		printf("Stack Full\n");
	else
		top=top+1;
		stk[top]=e;
}
int pop()
{
	int x;	
	if(top==-1)
		printf("Stack Empty\n");
	else
		x=stk[top];
		top--;
	return x;
}
void dfs(int i)
{
	int j,flag;	
	push(i);
	while(!stkempty())
	{
	i=pop();
		if(v[i]!=1)
		{
			printf("\nInside dfs ");
			v[i]=1;
			printf("V%d\n",i);
			flag=0;
			for(j=1;j<=n;j++)
			{
				if(am[i][j]==1 && v[j]!=1)
				{
					push(j);
					flag=1;
				}
				if(flag==1)
					break;
			}
		}
	}
}
int qempty()
{
	if(f-r==1)
		return 1;
	else
		return 0;
}
void addq(int i)
{
	if(r==19)
		printf("Queue Full\n");
	else
		r++;
		q[r]=i;
}
int delq()
{
	int j;	
	if(f-r==1)
		printf("Queue Empty\n");
	else
		j=q[f];
		f++;
}
void bfs(int i)
{
	int j,x;	
	addq(i);
	v[i]=1;
	while(!qempty())
	{
		x=delq();
		printf("V%d\n",x);
		for(j=1;j<=n;j++)
		{
			if(am[x][j]==1 && v[j]!=1)
			{
				addq(j);
				v[j]=1;
			}
		}
	}
}
void main()
{	
	int i,j,c,ch;	
	printf("\nEnter no. of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			printf("Is there any edge from %d to %d:(1/0)?\n",i,j);
			scanf("%d",&c);
			if(c==1)
			{
				am[i][j]=1;
				am[j][i]=1;
			}
		}
	}
	printf("\nAdjacency Matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",am[i][j]);
		}
		printf("\n");	
	}
	printf("Enter Your Choice:\n1.DFS Traversal\n2.BFS Traversal\n3.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			//recdfs(1);
			
			for(i=1;i<=n;i++)
				v[i]=0;
			dfs(1);
			break;
		case 2:
			bfs(1);
			break;
		case 3:
			exit(0);
		default:
			printf("Wrong Input!");
	}
}
