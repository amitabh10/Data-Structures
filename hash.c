#include<stdio.h>
#include<string.h>
struct faculty
{
	int id;
	char name[10];
	int subcode;
};
typedef struct faculty f;
int maxl=0;
int hash(f,int);
int check(f[][2],int,int);
void search(f[][2],int,int);
void accept(f[][2],int);
void display(f[][2],int);
void main()
{
	f f1[100][2];
	int ch,n,flag=0;
	do
	{
		printf("\n---------------HASHING---------------\n");
		printf("1.Add Data\n2.Search Data\n3.Display Table\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the no. of Faculty\n");
			scanf("%d",&n);	
			accept(f1,n);
			flag=1;
			break;

			case 2:
			if(flag==1)
			search(f1,maxl,n);
			else
			printf("\nNo Data Present in Table\n");
			break;
			
			case 3:
			if(flag==1)
			display(f1,maxl);
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
void search(f a[][2],int maxl,int n)
{
	int ad,found=0,i=0;
	f key;
	printf("\nEnter Faculty ID:");
	scanf("%d",&key.id);
	ad=hash(key,n);
	printf("\n%d",ad);
	while(!found && i<maxl)
	{
		if(key.id==a[ad][0].id)
		{
			key=a[ad][0];
			found=ad;
		}
		else
		{
			if(a[ad][1].id!=-1)
			ad=a[ad][1].id;
			else
			break;
		}
		i++;
	}
	if(!found)
	printf("\nFaculty does not exist\n");
	else
	{
		printf("\nFound at Index:%d",found);
		printf("\nID\tName\tSubcode");
		printf("\n%d\t%s\t%d",key.id,key.name,key.subcode);
	}	
}
int check(f a[][2],int key,int n)
{
	int ad,found,i;
	ad=key%n;
	found=0;
	while(!found && i<(2*n))
	{
		if(key==a[ad][0].id)
		{
			found=ad;
		}
		else
		{
			if(a[ad][1].id!=-1)
			ad=a[ad][1].id;
			else
			break;
		}
		i++;
	}
	return found;
}
void accept(f a[][2],int n)
{
	int i,j,addr,chk,p;
	int *link,plink;
	f t,t1;
	for(i=0;i<2*n;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j].id=-1;
			strcpy(a[i][j].name,"");
			a[i][j].subcode=-1;
		}
	}
	printf("Enter Faculty Details:\n");
	for(i=0;i<n;i++)
	{
		plink=-1;
		printf("\nEnter details of Faculty %d",i+1);
		printf("\nEnter Faculty ID:");
		scanf("%d",&t.id);
		printf("\nEnter Name:");
		scanf("%s",&t.name);
		printf("\nEnter Subject Code:");
		scanf("%d",&t.subcode);
		p=check(a,t.id,n);
		while(p)
		{
			printf("\nFaculty ID already present\nEnter correct:");
			scanf("%d",&t.id);
			p=check(a,t.id,n);
			j=0;
		}
		place: 
		addr=hash(t,n);
		//printf("\nPlacing");
		if(a[addr][0].id==-1)
		{
			//printf("\nIn case 1");
			a[addr][0]=t;
		}
		else
		{
			t1=a[addr][0];
			chk=hash(t1,n);
			link=&a[addr][1].id;
			if(chk!=addr)
			{
				//printf("\nIn case 2");
				for(j=0;j<n;j++)
				{
					if(a[j][1].id==addr)
					{
						a[j][1].id=-1;
						break;
					}
				}
				a[addr][0]=t;
				plink=*link;
				//printf("\nplink:%d\n",plink);
				*link=-1;
				t=t1;
				goto place;					
			}
			else if(*link==-1)
			{
				//printf("\nIn case 3");
				while(a[addr][0].id!=-1)
				addr++;
				*link=addr;
				a[addr][0]=t;
				//printf("\nplink:%d\n",plink);
				if(plink<2*n)
				{
					//printf("\nIn plink\n");
					a[addr][1].id=plink;
				}
			}
			else
			{
				//printf("\nIn case 4");
				while(*link!=-1)
				{
					addr=a[addr][1].id;
					link=&a[addr][1].id;
				}
				while(a[addr][0].id!=-1)
				addr++;
				*link=addr;
				a[addr][0]=t;
			}
		}
		if(maxl<=addr)
		maxl=addr+1;	
		//display(a,maxl);		
	}
	display(a,maxl);
}
void display(f a[][2],int n)
{
	int i;
	printf("\n----------Final Hash Table-----------\n");
	printf("\nID\tName\tSubcode\tLink");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s\t%d\t%d",a[i][0].id,a[i][0].name,a[i][0].subcode,a[i][1].id);
	}
	printf("\n-------------------------------------\n");
}
int hash(f a,int n)
{
	int i;
	i=a.id%n;
	return i;	
}
