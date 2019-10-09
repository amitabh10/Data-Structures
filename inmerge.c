#include<stdio.h>
#include<string.h>
#include<math.h> 
struct stud
{
	int rollno;
	int marks;
	char name[10];
};
typedef struct stud st;
void accept(st[]);
void display(st[],int);
void insert(st[]);
void merge(st[]);
void sort(st* [],int,int);
void main()
{
	int ch,n;
	st s[100];
	do
	{
		printf("\n\nSorting\n1.Insertion\n2.Merge\n3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			insert(s);
			break;
			case 2:
			merge(s);
			break;
			case 3:
			printf("Thankyou!\n");
			break;
			default:
			printf("Wrong Choice!\n");
			break;
		}
	}while(ch!=3);
}
void merge(st a[])
{
	int i,j,x,ncopy,ctr,n;
	st *p[100];
	printf("Enter no. of Students\n");
	scanf("%d",&n);
	for(i=n;i<100;i++)
	{
		a[i].rollno=0;
		a[i].marks=0;
		strcpy(a[i].name,"");
	}
	printf("Enter Student Details:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter details of student %d",i+1);
		printf("\nEnter Roll No:");
		scanf("%d",&a[i].rollno);
		printf("\nEnter name:");
		scanf("%s",&a[i].name);
		printf("\nEnter Marks:");
		scanf("%d",&a[i].marks);
		if(i>0)
		{
			for(j=0;j<i;j++)
			{
				while(a[i].rollno==a[j].rollno)
				{
					printf("\nRoll No. already present\nEnter correct:");
					scanf("%d",&a[i].rollno);
					j=0;
				}
			}
		}
	}
	x=1;
	ctr=0;
	while(ctr<n && n!=1)
	{
		for(i=pow(2,x);i<n || abs(n-i)<(pow(2,x)/2) ;i=i+pow(2,x))
		{
			ctr=0;
			printf("\n");
			for(j=i-pow(2,x);((j<i) && (j<n))||((n-j)<=((pow(2,x)/2)) && (j<n));j++)
			{
				printf("----%d----",j);
				if((a[j+1].rollno)!=0)
				{				
					p[ctr]=&a[j];
					ctr++;
				}
				else
				{
					p[ctr]=&a[j];
					ctr++;
					break;
				}
			}
			sort(p,ctr,x);
			display(a,n);
		}
		x++;
	}
	printf("\nSorted!");
	display(a,n);
}
void sort(st* a[],int n,int x)
{
	int i,j,ctr;
	st t[n];
	st k;
	for(i=0;i<pow(2,x)/2;i++)
		t[i]=*a[i];
	printf("\nRoll\tName\tMarks");
	for(i=0;i<pow(2,x)/2;i++)
	{
		printf("\n%d\t%s\t%d",(t[i]).rollno,(t[i]).name,(t[i]).marks);
	}
	for(i=pow(2,x)/2;i<n;i++)
	{
		k=*a[i];
		ctr=0;
		for(j=0;j<i;j++)
		{
			if((k).rollno>(t[j]).rollno)
			ctr++;
		}
		for(j=n-1;j>ctr;j--)
		{
			t[j]=t[j-1];
		}
		t[ctr]=k;		
	}
	printf("\nRoll\tName\tMarks");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s\t%d",(t[i]).rollno,(t[i]).name,(t[i]).marks);
	}
	for(i=0;i<n;i++)
	{
		*a[i]=t[i];
	}
	printf("\nRoll\tName\tMarks");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s\t%d",(*a[i]).rollno,(*a[i]).name,(*a[i]).marks);
	}	
}
void insert(st s[])
{
	int x,i,j,ctr;
	st t;
	printf("\nEnter the no. of Students you want to add:");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		s[i].rollno=0;
		s[i].marks=0;
		strcpy(s[i].name,"");
	}
	for(i=0;i<x;i++)
	{
		printf("\nEnter details of student %d",i+1);
		printf("\nEnter Roll No:");
		scanf("%d",&t.rollno);
		printf("\nEnter name:");
		scanf("%s",&t.name);
		printf("\nEnter Marks:");
		scanf("%d",&t.marks);
		if(i>0)
		{
			for(j=0;j<i;j++)
			{
				while(t.rollno==s[j].rollno)
				{
					printf("\nRoll No. already present\nEnter correct:");
					scanf("%d",&t.rollno);
					j=0;
				}
			}
		}
		ctr=0;
		//printf("\nCounting");
		for(j=0;j<i;j++)
		{
			if(t.rollno>s[j].rollno)
			ctr++;
		}
		//printf("\n%d",ctr);
		for(j=x-1;j>ctr;j--)
		{
			s[j]=s[j-1];
		}
		s[ctr]=t;
		//printf("\nCurrent Array:\n");
		//display(s,x);
	}
	printf("\nSorted:\n");
	display(s,x);
}
void display(st s[],int n)
{
	int i;
	printf("\nRoll\tName\tMarks");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s\t%d",s[i].rollno,s[i].name,s[i].marks);
	}
}
