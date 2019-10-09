/*WAP to implement Bubble sort and Quick Sort on 1D array of Student structure (contains student_name, student_roll_no,
total_marks), with key as student_roll_no. And count the number of swap performed.*/

#include<stdio.h>
#include<stdlib.h>
struct stud
{
	char name[30];
	int roll;
	int marks;
};
typedef struct stud s;
s a[20];
int n,ct=0;
void disp(int ctr,s a[])
{
	int i;
	printf("\nSorted list acc to roll no.s is:\n");
	printf("\nSr No.\t Name\t Roll No\tMarks\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t %s\t %d\t %d\n",i+1,a[i].name,a[i].roll,a[i].marks);
	}
	printf("\nNo. of swaps performed:%d\n",ctr);
}
void quick(s a[],int st,int end)
{
	int k,j;
	s t;
	if(st<=end)
	{
		k=end;
		for(j=st;j<k;j++)
		{
			if(a[j].roll>a[j+1].roll)
			{
				ct++;				
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			else
			{
				ct++;				
				t=a[j+1];
				a[j+1]=a[k];
				a[k]=t;
				j--;
				k--;
			}
		}
		quick(a,st,k-1);
		quick(a,k+1,end);
	}
	
}
void bubble(s a[])
{
	int ctr=0,i,j;
	s t;	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j].roll>a[j+1].roll)
			{
				ctr++;				
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	disp(ctr,a);
}
void main()
{
	int i,j,c;
	printf("Enter the no. of students:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("*****Details of Student %d*****\n",i+1);
		printf("Name:");
		scanf("%s",a[i].name);
		printf("Roll No:");
		scanf("%d",&a[i].roll);
		printf("Total Marks:");
		scanf("%d",&a[i].marks);
	}
	/*for(j=0;j<n;j++)
	{
		printf("\n*****Details of Student %d*****\n",j+1);
		printf("Name:%s\n",a[j].name);
		printf("Roll No:%d\n",a[j].roll);
		printf("Total Marks:%d\n",a[j].marks);
	}*/
		printf("\nEnter Your Choice:\n1.Bubble Sort\n2.Quick Sort\n3.Exit\n");
		scanf("%d",&c);
		if(c==1)
			bubble(a);
		else if(c==2)
		{			
			quick(a,0,n-1);
			disp(ct,a);
		}
		else
			exit(0);
}
