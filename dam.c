#include<stdio.h>
#define infi 9999
int top=-1,am[20][20]={0},n,stk[20],q[20],r=-1,f=0;
void accept()
{
	int e,u,v,i=0,cost;
	printf("\nNo. of vertices:");
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
			i++;
		}
	}
}
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
void addq(int k)
{
	if(r==19)
		printf("\nQueue Full!\n");
	else
	{
		r++;
		q[r]=k;
	}
}
int delq()
{
	int x;	
	if(f-r==1)
		printf("\nQueue Empty!\n");
	else
	{
		x=q[f];
		f++;
		return x;
	}

}
int qempty()
{
	if(f-r==1)
	{
		//printf("\nQueue Empty!\n");
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int y)
{
	if(top==19)
		printf("\nStack Full!\n");
	else
	{
		top++;
		stk[top]=y;
	}
}
int pop()
{
	int x;	
	if(top==-1)
		printf("\nStack Empty!\n");
	else
	{
		x=stk[top];
		top--;
		return x;
	}
}
int stkempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void dfs(int i)
{
	int j,p,v[20]={0};		
	push(i);
	v[i]=1;
	do
	{
		p=pop();
		printf("V%d\n",p);
		for(j=1;j<=n;j++)
		{
			if(am[p][j]==1 && v[j]!=1)
			{
				push(j);
				v[j]=1;
				break;
			}
		}
	}while(!stkempty());
}
void bfs(int i)
{
	int j,p,v[20]={0};
	addq(i);
	v[i]=1;
	do
	{
		p=delq();
		printf("V%d\n",p);
		for(j=1;j<=n;j++)
		{
			if(am[p][j]==1 && v[j]!=1)
			{
				addq(j);
				v[j]=1;
			}
		}
	}while(!qempty());
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
void dijkstra(int i)
{
	int j,k,min,ctr=1,sum=0,strt=i,minv;
	int v[20]={0};
	int op[20]={0};
	int path[20]={0};
	int fin[20][20]={0};
	path[ctr]=i;
	v[i]=1;
	ctr++;
	for(j=1;j<=n;j++)	//zero->infi in AM
	{
		for(k=1;k<=n;k++)
		{
			if(am[j][k]==0 && j!=k)
				am[j][k]=infi;
		}	
	}
	printf("\nAdjacency Matrix for Dijkstra's Algo:\n");
	repam();
	for(j=1;j<=n;j++)
	{
		op[j]=am[i][j];		//V ith row in output array
	}
	for(k=1;k<=n;k++)
	{
		if(am[i][k]>0 && am[i][k]<infi)		//Storing the direct path of cost values in fin
		{
			fin[k][0]=i;
			fin[k][1]=k;
		}
	}
	//printf("\nStoring in output array!\n");
	do{
		//printf("\nInside do\n");		
		min=infi;
		for(j=1;j<=n;j++)
		{
			//printf("\nInside for\n");			
			if(am[i][j]>0 && am[i][j]<min && v[j]!=1)
			{
				min=am[i][j];		//taking min of all adjacents of v ith row
				minv=j;
			}
		}
		path[ctr]=minv;		//Storing "to" vertex(destination) to compare cost with op array
		v[minv]=1;
		sum=sum+min;
		ctr++;
		if(sum<op[minv])
		{
			op[minv]=sum;
			for(j=0;j<ctr;j++)
				fin[minv][j]=path[j+1];		//Storing the min indirect path found
		}
		i=minv;
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
			while(fin[i][j]!=0)
			{
				printf("V%d->",fin[i][j]);
				j++;
			}
			printf("end\n");
		}
	}
}		
void main()
{
	accept();
	printf("\nAdjacency Matrix is:\n");
	repam();
	/*printf("\nBFS Traversal is:\n");
	bfs(1);
	printf("\nDFS Traversal is:\n");
	dfs(1);*/
	printf("\nBy Dijkstra's Algo:\n");
	dijkstra(1);
}
