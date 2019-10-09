//PRIM(AM)
#include<stdio.h>
#define infi 9999
struct c
{
	int u;
	int v;
	int value;
};
typedef struct c edge;
edge c,set[20];
int n,setctr=0,belong[20],am[20][20];
void repam()
{
	int i,j;	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",am[i][j]);
		}
		printf("\n");
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
void prim(int st)
{
	int v[20]={0};
	int i,j,ctr1,sum=0;
	edge min,uv[20],t;
	v[st]=1;
	ctr1=0;
	for(i=1;i<=n;i++)	//zero->infi in AM
	{
		for(j=1;j<=n;j++)
		{
			if(am[i][j]==0 && i!=j)
				am[i][j]=infi;
		}	
	}
	while(!allvisit(v))
	{
		min.value=9999;
		for(i=1;i<=n;i++)
		{
			if(am[st][i]>0 && am[st][i]<infi && v[i]!=1)
			{
				c.u=st;
				c.v=i;
				c.value=am[st][i];
				if(min.value>am[st][i])
				{	
					min=c;
				}
				else
				{
					uv[ctr1]=c;
					ctr1++;			
				}	
			}
		}
		for(i=0;i<ctr1;i++)
		{
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
	int e,i=0,u,v,sum=0,cost;	
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nNo. of edges:");
	scanf("%d",&e);
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
			am[u][v]=cost;
			am[v][u]=cost;
			i++;
		}
	}
	printf("\nAdjacency Matrix is:\n");
	repam();
	prim(1);
}

