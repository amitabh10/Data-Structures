/*WAP to implement Shell sort and Bucket Sort on 1D array of Employee structure (contains employee_name, emp_no,emp_salary), with key as emp_no. And count the number of swap performed.*/

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
	int i,j,ct=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(b[i][j].emp_no!=0)
			{
				a[ct]=b[i][j];
				ct++;
			}
		}
	}
}
void bucket()
{
	int max=0,i,j,pass=0,d,x,k;
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
			for(x=0;x<n;x++)
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
void shell()
{
	int f,i,ctr=0;
	e t;	
	printf("Enter the hopping frequency(f>%d):",n/2);
	scanf("%d",&f);
	if(f>n/2)
	{
		while(f>0)
		{
			for(i=0;i<n-f;i++)
			{
				if(a[i].emp_no>a[i+f].emp_no)
				{
					ctr++;					
					t=a[i];
					a[i]=a[i+f];
					a[i+f]=t;
				}
			}
			f--;
		}
		disp(ctr,a);
	}
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
	printf("\nEnter Your Choice:\n1.Shell Sort\n2.Bucket Sort\n3.Exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			shell();
			break;
		case 2:
			bucket();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Wrong Input!");
			break;
	}

}
