
#include<stdio.h>
struct employee
{
	char name[30];
	int id;
	int salary;
};
typedef struct employee emp;
void display(emp,int);
void accept(emp[],int);
void rsearch(emp[],int);
int search(emp[],int,int);
int fibsearch(emp[],int,int,int);
int f[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711};
void main()
{
	int l,i,ch,key,res,flag=0;
	emp e[10];
	do
	{
		printf("\n*******FIBONACCI SEARCH*******\n1.Add Data\n2.Search with Recursion\n3.Search without Recursion\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the no. of employees:\n");
			scanf("%d",&l);
			accept(e,l);
			flag=1;
			break;
			
			case 2:
			if(flag==0)
			printf("\nNo Data!\n");
			else
			rsearch(e,l);
			break;

			case 3:
			if(flag==0)
			printf("\nNo Data!\n");
			else
			printf("\nEnter the ID:");
			scanf("%d",&key);	
			res=search(e,l,key);
			if(res!=-1)
			display(e[res],res);
			else
			printf("\nNot Found!");
			break;
			
			case 4:
			printf("\nThankyou!\n");
			break;
			
			default:
			printf("\nWrong Choice!\n");
			break;
		}		
	}while(ch!=4);
}
void display(emp e,int loc)
{
	printf("\n-------------------------\n");
	printf("Found at location:%d\n",loc+1);
	printf("\nName:%s",e.name);
	printf("\nID:%d",e.id);
	printf("\nSalary:%d",e.salary);
	printf("\n-------------------------\n");	
}
void rsearch(emp e[],int n)
{
	int res,key;
	printf("\nEnter the ID:");
	scanf("%d",&key);
	res=fibsearch(e,0,n,key);
	if(res!=-1)
		display(e[res],res);
	else
	printf("\nNot Found!");
}
int search(emp a[],int n,int key)
{
	int m,k,i,ctr=0;
	emp b[n];
	i=0;
	m=1;		
	while(m!=0)
	{
		i=0;
		while(n>f[i])
		i++;
		m=f[i-1];
		if(a[m].id==key)
		return m;
		else if(a[m].id>key)
		{
			n=m;
		}
		else
		{
			for(i=m+1;i<n;i++)
			{
				b[i]=a[i];
				ctr++;
			}
			for(i=0;i<ctr;i++)
			a[i]=b[i];
			n=ctr;
		} 
	}
	return -1;	
}
void accept(emp e[],int n)
{
		int i,j,t;
		printf("Enter Employees:\n");
		for(i=0;i<n;i++)
		{
			printf("\nEnter details of Employee %d",i+1);
			printf("\nEnter Name:");
			scanf("%s",e[i].name);
			printf("\nEnter ID:");
			scanf("%d",&t);
			for(j=0;j<i;j++)
			{
				while(t==e[j].id)
				{
					printf("\nID Already Exists!Enter Correct ID:");
					scanf("%d",&t);
					j=0;
				}
			}
			e[i].id=t;
			printf("\nEnter Salary:");
			scanf("%d",&e[i].salary);
		}
}
int fibsearch(emp a[],int st,int cnt,int k)
{
	int i,m,ctr=0;
	i=0;
	m=0;
	while(cnt>f[i])
	{
		i++;
	}
	if(i==0)
	return -1;	
	m=f[i-1];
	if(a[st+m].id==k)
	return st+m;
	else if(a[st+m].id>k)
	{
		return fibsearch(a,0,m,k);
	}
	else
	{
		for(i=st+m;i<cnt;i++)
		ctr++;
		return fibsearch(a,m,ctr,k);
	}
}
/*OUTPUT:-
nidhi@nidhi-Inspiron-5523:~$ cd Desktop
nidhi@nidhi-Inspiron-5523:~/Desktop$ gcc fibs.c
nidhi@nidhi-Inspiron-5523:~/Desktop$ ./a.out

*******FIBONACCI SEARCH*******
1.Add Data
2.Search with Recursion
3.Search without Recursion
4.Exit
1
Enter the no. of employees:
5
Enter Employees:

Enter details of Employee 1
Enter Name:Nidhi

Enter ID:4

Enter Salary:45000

Enter details of Employee 2
Enter Name:Neha

Enter ID:8

Enter Salary:50000

Enter details of Employee 3
Enter Name:Amit

Enter ID:16

Enter Salary:46000

Enter details of Employee 4
Enter Name:Omkar

Enter ID:20

Enter Salary:45000

Enter details of Employee 5
Enter Name:Christine

Enter ID:32

Enter Salary:45000

*******FIBONACCI SEARCH*******
1.Add Data
2.Search with Recursion
3.Search without Recursion
4.Exit
2

Enter the ID:8

-------------------------
Found at location:2

Name:Neha
ID:8
Salary:50000
-------------------------

*******FIBONACCI SEARCH*******
1.Add Data
2.Search with Recursion
3.Search without Recursion
4.Exit
3

Enter the ID:16

-------------------------
Found at location:3

Name:Amit
ID:16
Salary:46000
-------------------------

*******FIBONACCI SEARCH*******
1.Add Data
2.Search with Recursion
3.Search without Recursion
4.Exit
4

Thankyou!
nidhi@nidhi-Inspiron-5523:~/Desktop$ */
