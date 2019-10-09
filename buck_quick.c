/*WAP to implement Bucket Sort and Quick sort on 1D array of Faculty structure (contains faculty_name, faculty_ID, subject_codes,
class_names), with key as faculty_ID. And count the number of swap performed*/

#include<stdio.h>
#include<stdlib.h>
struct faculty
{
	char name[30];
	int id;
	int code;
	char class[5];
};
typedef struct faculty f;
f a[10];
int n,ctr=0;
void disp(int cr,f a[])
{
	int i;	
	printf("\nSorted list acc to id is:\n");
	printf("Name\t ID\t Code\t Class\n");
	//printf("\nn=%d\n",n);	
	for(i=0;i<n;i++)
	{
		printf("%s\t %d\t %d\t %s\n",a[i].name,a[i].id,a[i].code,a[i].class);
	}
	printf("\nNo. of swaps performed=%d\n",cr);
}
void quick(f a[],int st,int end)
{
	int k,j;
	f t;
	if(st<=end)
	{
		k=end;
		for(j=st;j<k;j++)
		{
			if(a[j].id>a[j+1].id)
			{
				ctr++;				
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			else
			{
				ctr++;				
				t=a[j+1];
				a[j+1]=a[k];
				a[k]=t;
				k--;
				j--;
			}
		}
		quick(a,st,k-1);
		quick(a,k+1,end);
	}
}
void compute(f b[10][10])
{
	int i,j,ct=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(b[i][j].id!=0)
			{
				a[ct]=b[i][j];
				ct++;
			}
		}
	}
}
void bucket()
{
	int i,max=0,j,pass=0,x,d,k;
	f b[10][10];	
	for(i=0;i<n;i++)
	{
		if(max<a[i].id)
			max=a[i].id;
	}
	j=max;
	while(j>0)
	{
		j=j/10;
		pass++;
	}
	j=pass;
	while(j>0)
	{
		for(i=0;i<10;i++)
		{
			for(k=0;k<10;k++)
			{
				b[i][k].id=0;
			}
		}
		for(i=0;i<n;i++)
		{
			d=a[i].id;
			k=pass-j;
			while(k>0)
			{
				d=d/10;
				k--;
			}
			d=d%10;
			for(x=0;x<10;x++)
			{
				if(b[d][x].id==0)
				{
					b[d][x]=a[i];
					break;
				}
			}
		}
		compute(b);
		j--;
	}
	disp(0,a);
}
void main()
{
	int i,c;	
	printf("\nEnter the no. of faculty:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n*****Details of Faculty %d*****\n",i+1);
		printf("Name:");
		scanf("%s",a[i].name);
		printf("ID:");
		scanf("%d",&a[i].id);
		printf("Subject code:");
		scanf("%d",&a[i].code);
		printf("Class name:");
		scanf("%s",a[i].class);
	}
	printf("\nEnter Your Choice:\n1.Bucket Sort\n2.Quick Sort\n3.Exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			bucket();
			break;
		case 2:
			quick(a,0,n-1);
			disp(ctr,a);
			break;
		case 3:
			exit(0);
		default:
			printf("Wrong Input!");
			break;
	}
}
