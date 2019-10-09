#include<stdio.h>
int l=0;
void display(int a[][2])
{
	int i;
	printf("\n----------Final Hash Table-----------\n");
	printf("\nIndex\tID\tLink");
	for(i=0;i<l;i++)
	{
		printf("\n%d\t%d\t%d",i,a[i][0],a[i][1]);
	}
	printf("\n-------------------------------------\n");
}
int hash(int a,int n)
{
	int i;
	i=a%n;
	return i;	
}

int check(int a[][2],int key,int n)
{
	int ad,found,i;
	ad=hash(key,n);
	found=-1;
	i=0;
	while(found==-1 && i<l)
	{
		if(key==a[ad][0])
		{
			found=ad;
		}
		else
		{
			if(a[ad][1]!=-1)
			ad=a[ad][1];

			else
			break;
		}
		i++;
	}
	return found;
}
void search(int a[][2],int n)
{
	int ad,found[100],i=0,chk;
	int key[100],s,ctr=0;
	printf("Enter no. of Elements in subset\n");
	scanf("%d",&s);
	printf("\nEnter Numbers in Subset:\n");
	for(i=0;i<s;i++)
	{
		scanf("%d",&key[i]);
	}
	for(i=0;i<s;i++)
	{
		chk=check(a,key[i],n);
		if(chk==-1)
		break;
		else
		{
			found[ctr]=chk;
			ctr++;
		}
	}
	if(ctr==s)
	{
		printf("It is a subset!");
		printf("\nFound at:");
		printf("\nIndex\tID");
		for(i=0;i<s;i++)
		printf("\n%d\t%d",found[i],a[found[i]][0]);
	}
	else
	printf("\nNot a Subset!");			
}

void place(int a[][2],int t,int n,int plink)
{
	int j,addr,chk,t1;
	int *link;
	addr=hash(t,n);
	if(a[addr][0]==-1)
	{
		a[addr][0]=t;
	}
	else
	{
		t1=a[addr][0];
		chk=hash(t1,n);
		link=&a[addr][1];
		if(chk!=addr)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][1]==addr)
				{
					a[j][1]=-1;
					break;
				}
			}
			a[addr][0]=t;
			plink=*link;
			*link=-1;
			t=t1;	
			place(a,t,n,plink);					
		}
		else if(*link==-1)
		{
			while(a[addr][0]!=-1)
			addr++;
			*link=addr;
			a[addr][0]=t;
			if(plink<2*n)
			{
				a[addr][1]=plink;
			}
		}
		else
		{
			while(*link!=-1)
			{
				addr=a[addr][1];
				link=&a[addr][1];
			}
			while(a[addr][0]!=-1)
			addr++;
			*link=addr;
			a[addr][0]=t;
		}
	}
	if(l<=addr)
	l=addr+1;			
}
void accept(int a[][2],int n)
{
	int i,t,j;
	for(i=0;i<2*n;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("Enter Numbers in Set:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter Number %d:",i+1);
		scanf("%d",&t);
		place(a,t,n,-1);
	}
	display(a);
}
void main()
{
	int f1[100][2];
	int ch,n,flag=0;
	do
	{
		printf("\nHASHING\n");
		printf("1.Add Set\n2.Search Subset\n3.Display Table\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the no. of Elements in Set\n");
			scanf("%d",&n);	
			accept(f1,n);
			flag=1;
			break;

			case 2:
			if(flag==1)
			search(f1,n);
			else
			printf("\nNo Data Present in Table\n");
			break;
			
			case 3:
			if(flag==1)
			display(f1);
			else
			printf("\nNo Data Present in Table\n");
			break;
			
			case 4:
			printf("\nThankyou!\n");
			break;
			
			default:
			printf("\nWrong Choice!\n");
		}
	}while(ch!=4);		
}

