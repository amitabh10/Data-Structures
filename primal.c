//PRIM(AM)
#include<stdio.h>
#include<stdlib.h>
#define infi 9999
struct c
{
	int u;
	int v;
	int value;
};
typedef struct c edge;
edge c,set[20];
struct list
{
	int v;
	int cost;
	struct list *next;
};
typedef struct list l;
l *h[20];
int n,setctr=0,belong[20],am[20][20];
l *createnode(int tx,int wtx)
{
	l *j;
	j=malloc(sizeof(l));
	if(j==NULL)
		printf("\nMemory Shortage!\n");
	else
	{
		j->v=tx;
		j->cost=wtx;
		j->next=NULL;
		return j;
	}
}
int allvisit(int v[])
{
	int i;	
	for(i=1;i<=n;i++)
	{
		if(v[i]==0)
			return 0;
	}
	return 1;
}
void repal()
{
	int i;
	l *q;
	for(i=1;i<=n;i++)
	{
		q=h[i];
		printf("\nV%d::",i);
		while(q!=NULL)
		{
			printf("V%d->",q->v);
			q=q->next;
		}
		printf("null\n");
	}
}
void prim(int st)
{
	int v[20]={0};
	int i,j,ctr1,sum=0;
	l *p;
	edge min,uv[20],t;
	v[st]=1;
	ctr1=0;
	while(!allvisit(v))
	{
		min.value=9999;
		printf("\n------%d----------\n",st);
		p=h[st];
		while(p!=NULL)
		{
			if(v[p->v]!=1)
			{
				c.u=st;
				c.v=p->v;
				c.value=p->cost;
				if(min.value>p->cost)
				{	
					min=c;
				}
				else
				{
					uv[ctr1]=c;
					ctr1++;			
				}	
			}
			p=p->next;
		}
		for(i=0;i<ctr1;i++)
		{
			printf("\nComparing %d & %d\n",min.value,uv[i].value);
			if(min.value>uv[i].value)
			{
				t=min;
				min=uv[i];
				uv[i]=t;
			}
		}
		set[setctr]=min;
		setctr++;
		v[min.v]=1;
		st=min.v;
	}
	printf("\nAFTER PRIM\nF\tT\tV\n");
	for(i=0;i<setctr;i++)
	{
		printf("%d\t%d\t%d\n",set[i].u,set[i].v,set[i].value);
		sum=sum+set[i].value;
	}
	printf("Total Cost:%d\n",sum);
}
void main()
{
	int e,i=0,u,v,sum=0,k,cost;
	l *new,*p;
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nNo. of edges:");
	scanf("%d",&e);
	for(k=1;k<=n;k++)
		h[k]=NULL;
	while(i<e)
	{
		printf("\nEnter edge(u,v):");
		scanf("%d%d",&u,&v);
		if(u<=0 || u>n || v<=0 || v>n)
		{
			printf("\nWrong Input!");
		}
		else
		{
			printf("\nIts cost:\n");
			scanf("%d",&cost);
			new=createnode(v,cost);
			if(h[u]==NULL)
				h[u]=new;
			else
			{
				p=h[u];
				while(p->next!=NULL)
				{
					p=p->next;
				}
				p->next=new;
			}
			new=createnode(u,cost);
			if(h[v]==NULL)
				h[v]=new;
			else
			{
				p=h[v];
				while(p->next!=NULL)
				{
					p=p->next;
				}
				p->next=new;
			}
			i++;
		}
	}
	printf("\nAdjacency List is:\n");
	repal();
	prim(1);
}

