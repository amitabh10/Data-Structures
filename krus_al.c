#include<stdio.h>
struct c
{
	int f;
	int t;
	int value;
};
typedef struct c edge;
edge c[20] ,set[20];
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
void sort(edge d[],int e)
{
	int i,j;
	edge t;
	for(i=0;i<e-1;i++)
	{
		for(j=0;j<e-1;j++)
		{
			if(d[j].value>d[j+1].value)
			{
				t=d[j];
				d[j]=d[j+1];
				d[j+1]=t;
			}
		}
	}
}
int replace(int b[],int c1,int c2,int e)
{
	int i;
	for(i=1;i<e;i++)
	{
		if(b[i]==c2)
			b[i]=c1;
	}
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
void main()
{
	int k,e,i=0,u,v,sum=0,cost;
	l *p,*new;	
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
			c[i].f=u;
			c[i].t=v;
			c[i].value=cost;
			i++;
		}
	}
	printf("\nAdjacency List is:\n");
	repal();
	sort(c,e);
	printf("\nSorted List\n");
	printf("\nF\tT\tV\n");
	for(i=0;i<e;i++)
	{
		printf("%d\t%d\t%d\n",c[i].f,c[i].t,c[i].value);	//Edge table
	}
	for(i=1;i<=n;i++)
		belong[i]=i;	//initial values
	for(i=0;i<e;i++)	//chk
	{
		u=belong[c[i].f];
		v=belong[c[i].t];
		if(u!=v)
		{
			set[setctr]=c[i];
			setctr++;
			replace(belong,u,v,e);
		}	
	}
	printf("\nAFTER KRUSKAL\nF\tT\tV\n");
	for(i=0;i<setctr;i++)
	{
		printf("%d\t%d\t%d\n",set[i].f,set[i].t,set[i].value);
		sum=sum+set[i].value;
	}
	printf("Total Cost:%d\n",sum);
	
}

