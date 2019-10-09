//BFS,DFS,Djikstra(AL)
#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int vx;
	int cost;
	struct graph *next;
};
typedef struct graph vertex;
vertex *h[20],*stk[20],*q[20];
int n,top,frnt,rear;
vertex *createnode(int tx,int wtx)
{
	vertex *j;
	j=malloc(sizeof(vertex));
	if(j==NULL)
		printf("\nMemory Shortage!\n");
	else
	{
		j->vx=tx;
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
void dijkstra()
{
	int st,ctr=0,strt,i,j,sum=0;
	int v[20]={0};
	int finpath[20][20]={0};
	int op[20];
	int path[20];
	vertex *min,*p;
	printf("\nEnter starting point:");
	scanf("%d",&st);
	p=h[st];
	for(i=1;i<=n;i++)
		op[i]=9999;
	op[st]=0;
	v[st]=1;
	path[ctr]=st;
	ctr++;
	strt=st;
	for(i=1;i<=n;i++)
	{
		while(p!=NULL)
		{
			op[p->vx]=p->cost;
			finpath[p->vx][0]=st;
			finpath[p->vx][1]=p->vx;
			p=p->next;
		}
	}
	do
	{
		p=h[st];
		min=createnode(0,9999);
		while(p!=NULL)
		{
			if(p->cost<min->cost)
				min=p;
			p=p->next;
		}
		sum=sum+min->cost;
		path[ctr]=min->vx;
		v[min->vx]=1;
		ctr++;
		if(op[min->vx]>sum)
		{
			op[min->vx]=sum;
			for(i=0;i<ctr;i++)
			{
				finpath[min->vx][i]=path[i];
			}
		}
		st=min->vx;
		free(min);
	}while(!allvisit(v));
	printf("\nStarting pt:V%d\n",strt);	//Displaying
	for(i=1;i<=n;i++)
	{
		printf("\nDistance of node %d:%d\nPath=",i,op[i]);
		j=0;
		if(i==strt)
		{
			printf("V%d\n",i);
		}
		else
		{
			while(finpath[i][j]!=0)
			{
				printf("V%d->",finpath[i][j]);
				j++;
			}
			printf("end\n");
		}
	}
}
void addq(vertex *k)
{
	if(rear==19)
		printf("\nQueue Full!\n");
	else
	{
		rear++;
		q[rear]=k;
	}
}
vertex *delq()
{
	vertex *x;	
	if(frnt-rear==1)
		printf("\nQueue Empty!\n");
	else
	{
		x=q[frnt];
		frnt++;
		return x;
	}

}
int qempty()
{
	if(frnt-rear==1)
	{
		//printf("\nQueue Empty!\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
void bfs(int s)
{
	rear=-1,frnt=0;
	int v[20]={0};	
	vertex *p;
	printf("\nV%d->",s);
	v[s]=1;
	do
	{
		if(!qempty())
		{
		p=delq();
		printf("V%d->",p->vx);
		s=p->vx;
		}
		p=h[s];
		while(p!=NULL)
		{
			if(v[p->vx]!=1)
			{
				addq(p);
				v[p->vx]=1;
			}
			p=p->next;
		}
	}while(!qempty());
	printf("end");
}
void push(vertex *x)
{
	if(top==19)
		printf("\nStack Full!\n");
	else
	{
		top++;
		//printf("\nAdd %d\n",x->vx);
		stk[top]=x;
	}
}
vertex *pop()
{
	vertex *y;	
	if(top==-1)
		printf("\nStack Empty!\n");
	else
	{
		y=stk[top];
		//printf("\nDEl %d\n",y->vx);
		top--;
		return y;
	}
}
int stkempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void dfs(int s)
{
	top=-1;
	int v[20]={0};	
	vertex *p;
	printf("\nV%d->",s);
	v[s]=1;
	do
	{
		if(!stkempty())
		{
		p=pop();
		printf("V%d->",p->vx);
		s=p->vx;
		}
		p=h[s];
		while(p!=NULL)
		{
			if(v[p->vx]!=1)
			{
				push(p);
				v[p->vx]=1;
				break;
			}
			p=p->next;
		}
	}while(!stkempty());
	printf("end");
}
void repal()
{
	int i;
	vertex *q;
	for(i=1;i<=n;i++)
	{
		q=h[i];
		printf("\nV%d::",i);
		while(q!=NULL)
		{
			printf("V%d->",q->vx);
			q=q->next;
		}
		printf("null\n");
	}
}
void main()
{
	int i,e,f,t,wt;
	vertex *p,*new;	
	printf("\nEnter no. of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		h[i]=NULL;
	printf("\nEnter no. of edges:");
	scanf("%d",&e);
	i=1;
	while(i<=e)
	{
		printf("\nEnter edge(u,v):");
		scanf("%d%d",&f,&t);
		printf("\nIts cost:");
		scanf("%d",&wt);
		if(f>0 && f<=n && t>0 && t<=n)
		{
			new=createnode(t,wt);
			if(h[f]==NULL)
			{
				h[f]=new;
			}
			else
			{
				p=h[f];
				while(p->next!=NULL)
					p=p->next;
				p->next=new;
			}
			i++;
		}
		else
		{
			printf("\nWrong Input!\n");
		}	
	}
	printf("\nAdjacency List is:\n");
	repal();
	printf("\nDFS Traversal:\n");
	dfs(1);
	printf("\nBFS Traversal:\n");
	bfs(1);
	printf("\nDijkstra's:\n");
	dijkstra();
} 
