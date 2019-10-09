/*Adjacency list-DFS/BFS*/
#include<stdio.h>
#include<stdlib.h>
struct adj
{
	int v;
	struct adj *next;
};
typedef struct adj list;
list *a[10];
int q[20];
int v[20]={0},n,f=0,r=-1;
list *accept(int j)
{
	list *q;
	q=malloc(sizeof(list));
	q->v=j;
	q->next=NULL;
	return q;
}
void display(list *p)
{
	while(p!=NULL)
	{
		printf("V%d->",p->v);
		p=p->next;
	}
	printf("null\n");
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
void vempty()
{
	int i;
	for(i=1;i<=n;i++)
	{
		v[i]=0;
	}
}
void bfs(int i)
{
	int temp,temp1;
	list *j,*p;
	//printf("V%d\n",i);
	v[i]=1;
	addq(i);
	while(!qempty())
	{
		temp=delq();
		printf("V%d",temp);
		p=a[temp];
		while(p!=NULL)
		{
			if(v[p->v]!=1)
			{
				addq(p->v);
				v[p->v]=1;
			}
		}
	}
}
void recdfs(int i)
{
	list *p;
	printf("V%d\n",i);
	p=a[i];
	v[i]=1;
	while(p!=NULL)
	{
		i=p->v;
		if(v[i]!=1)
			recdfs(i);
		p=p->next;
	}
}
void main()
{
	list *p,*temp;
	int j,c,i;
	printf("No. of vertices:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a[i]=NULL;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Is there any edge from %d to %d:(1/0)?",i,j);
			scanf("%d",&c);
			if(c==1)
			{
				temp=accept(j);
				if(a[i]==NULL)
					a[i]=temp;
				else
				{
					p=a[i];
					while(p->next!=NULL)
						p=p->next;
					p->next=temp;
				}
			}
		}
	}
	printf("\nAdjacency List:\n");
	for(i=1;i<=n;i++)
	{
		printf("\n");	
		printf("V%d-",i);	
		display(a[i]);	
	}
	printf("\nDFS Traversal:-\n");
	//printf("\nRecursive:\n");
	recdfs(1);
	vempty();
	printf("BFS Traversal is:\n");
	bfs(1);
}
