/*WAP to implement Insertion sort and Quick Sort on 1D array of Student structure (contains student_name, student_roll_no,total_marks), with key as student_roll_no. And count the number of swap performed.*/

#include<stdio.h>
#include<stdlib.h>
struct stud
{
	char name[30];
	int roll;
	int marks;
};
typedef struct stud s;
s a[10];
int n,ctr,k,cr=0;
void disp(int ct,s a[])
{
	int i;
	printf("\nSorted list acc to roll no.s is:\n");
	printf("\nSr No.\t Name\t Roll No\tMarks\n");	
	for(i=0;i<n;i++)
	{
		printf("%d\t %s\t %d\t %d\n",i+1,a[i].name,a[i].roll,a[i].marks);
	}
	printf("\nNo. of swaps performed:%d\n",ct);
}
void quick(s b[],int st,int end)
{
	int k,i;
	s t;	
	if(st<=end)
	{
		k=end;
		for(i=st;i<k;i++)
		{
			if(b[i].roll>b[i+1].roll)
			{
				cr++;
				t=b[i];
				b[i]=b[i+1];
				b[i+1]=t;
			}
			else
			{
				cr++;				
				t=b[i+1];
				b[i+1]=b[k];
				b[k]=t;
				k--;
				i--;
			}
		}
		quick(b,st,k-1);
		quick(b,k+1,end);
	}
}
void insertion()
{
	int i,j;
	s t;
	for(i=0;i<n;i++)
		a[i].roll=0;
	for(i=0;i<n;i++)
	{
		printf("*****Details of Student %d*****\n",i+1);
		printf("Name:");
		scanf("%s",t.name);
		printf("Roll No:");
		scanf("%d",&t.roll);
		printf("Total Marks:");
		scanf("%d",&t.marks);
		ctr=0;
		for(j=0;j<i;j++)
		{
			if(t.roll>a[j].roll)
				ctr++;
		}
		for(j=n-1;j>ctr;j--)
			a[j]=a[j-1];
		a[ctr]=t;
	}
	disp(0,a);
}
void main()
{
	int i,j,c;
	printf("Enter the no. of students:");
	scanf("%d",&n);
	printf("\nEnter Your Choice:\n1.Insertion Sort\n2.Quick Sort\n3.Exit\n");
	scanf("%d",&c);
	if(c==1)
		insertion();
	else if(c==2)
	{	
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
		quick(a,0,n-1);
		disp(cr,a);
	}
	else
		exit(0);
}
