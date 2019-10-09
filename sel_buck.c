/*WAP to implement Selection sort and Bucket Sort on 1D array of Employee structure (contains employee_name, emp_no, emp_salary), with key as emp_no. And count the number of swap performed*/

#include<stdio.h>
#include<stdlib.h>
struct emp
{
	char name[30];
	int emp_no;
	int emp_sal;
};
typedef struct emp e;
e a[10];
int n;
void disp(int ctr,e a[])
{
	int i;
	printf("\nSorted list acc to emp no.s is:\n");
	printf("\nSr No.\t Name\t Emp No\t Emp Sal\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t %s\t %d\t %d\n",i+1,a[i].name,a[i].emp_no,a[i].emp_sal);
	}
	printf("\nNo. of swaps performed:%d\n",ctr);
}
void compute(e b[10][10])
{
	int i,j,cr=0;	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(b[i][j].emp_no!=0)
			{
				a[cr]=b[i][j];
				cr++;
			}
		}
	}
}
void bucket()
{
	int max=0;
	int i,j,d,k,x;
	int pass=0;
	e b[10][10];	
	for(i=0;i<n;i++)
	{
		if(max<a[i].emp_no)
			max=a[i].emp_no;
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
				b[i][k].emp_no=0;
				b[i][k].emp_sal=0;
			}
		}
		for(i=0;i<n;i++)
		{
			d=a[i].emp_no;
			k=pass-j;
			while(k>0)
			{
				d=d/10;
				k--;
			}
			d=d%10;
			for(x=0;x<10;x++)
			{
				if(b[d][x].emp_no==0)
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
void selection()
{
	int i,j,ctr=0;
	e t;	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].emp_no>a[j].emp_no)
			{
				ctr++;				
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	disp(ctr,a);
}
void main()
{
	int i,j,c;
	printf("Enter the no. of employees:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("*****Details of Employee %d*****\n",i+1);
		printf("Name:");
		scanf("%s",a[i].name);
		printf("Emp. No:");
		scanf("%d",&a[i].emp_no);
		printf("Emp. Salary:");
		scanf("%d",&a[i].emp_sal);
	}
	printf("\nEnter Your Choice:\n1.Selection Sort\n2.Bucket Sort\n3.Exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			selection();
			break;
		case 2:
			bucket();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("wrong");
			break;
	}
}
