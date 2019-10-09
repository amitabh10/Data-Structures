/*Write a Program for A bank simulation of its teller operation to see how waiting times would be affected by adding another teller. 4th march*/
#include<stdio.h>
#define max 5
struct customer
{
	char name[20];
	int wtime;
	int ttime;
};
typedef struct customer c;
c q[20][max];
int front[20],rear[20],n;
void init()
{
	int i;
	for(i=0;i<20;i++)
	{	
		front[i]=0;
		rear[i]=-1;
	}
}
void addq(c item,int i)
{
	rear[i]++;
	if(rear[i]==max)
	{
		printf("\nQueue Full\n");
	}
	else
	{
		q[i][rear[i]]=item;
		printf("\nAdded");
	}
}
c *delq(int i)
{
	c *x;
	if(rear[i]-front[i]==-1)
		printf("Queue is Empty!\n");
	else
	{
		x=&q[i][front[i]];
		front[i]++;
		return x;
	}
}
void accept()
{
	int i,j;
	c t;
	printf("\nEnter the no. of customers:");
	scanf("%d",&n);
	j=0;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			printf("\nEnter Name:");
			scanf("%s",t.name);
			printf("\nEnter time for transaction:");
			scanf("%d",&t.ttime);
			t.wtime=0;
			addq(t,j);
		}
		else if(i%5==0)
		{
			j++;
			printf("\nEnter Name:");
			scanf("%s",t.name);
			printf("\nEnter time for transaction:");
			scanf("%d",&t.ttime);
			t.wtime=0;
			addq(t,j);
		}
		else
		{
			printf("\nEnter Name:");
			scanf("%s",t.name);
			printf("\nEnter time for transaction:");
			scanf("%d",&t.ttime);
			t.wtime=0;
			addq(t,j);
		}
	}
}
void printq()
{
	int x,i,j;
	x=n/5;
	if(n%5==0)
		x--;
	for(i=0;i<=x;i++)
	{
		printf("\n**********Queue %d***********\n",i+1);
		printf("Name\tR.Time\tW.Time\n");
		for(j=front[i];j<=rear[i];j++)
		{
			printf("%s\t%d\t%d\n",(q[i][j]).name,(q[i][j]).ttime,(q[i][j]).wtime);
		}
	}	
}
void printfull()
{
	int x,i,j,ctr;
	x=n/5;
	ctr=0;
	if(n%5==0)
		x--;
	for(i=0;i<=x;i++)
	{
		printf("\n**********Queue %d***********\n",i+1);
		printf("Name\tR.Time\tW.Time\n");
		for(j=0;j<5 && ctr<n;j++)
		{
			printf("%s\t%d\t%d\n",(q[i][j]).name,(q[i][j]).ttime,(q[i][j]).wtime);
			ctr++;
		}
	}	
}
void simulate()
{
	int x=n/5,i,j,maxtime;
	int time[x+1];
	if(n%5==0)
		x--;
	c *t;
	printf("\n---------------------------------------------\n");
	for(i=0;i<=x;i++)
		time[i]=0;
	for(i=0;i<5 && i<n;i++)
	{
		for(j=0;j<=x;j++)
		{
			if(front[j]-rear[j]!=1)
			{
				t=delq(j);
				(*t).wtime=time[j];
				time[j]=time[j]+(*t).ttime;
			}
		}
		printf("\n---------------------------------------------\n");
		printq();
		printf("\n---------------------------------------------\n");
	}
	printf("\n-----------------------FINAL EVALUATION----------------------\n");
	printfull();
	maxtime=time[0];
	for(i=1;i<=x;i++)
	{
		if(maxtime<time[i])
			maxtime=time[i];
	}
	printf("\n---------------------------------------------\n");
	printf("Total Time of Activity:%d\n",maxtime);
	printf("Time Required in Tellers:\n");
	printf("Teller\tTime\n");
	for(i=0;i<=x;i++)
	printf("%d\t%d\n",i+1,time[i]);
	printf("\n---------------------------------------------\n");	
}
void main()
{
	init();
	accept();
	printq();
	simulate();
}
/*OUTPUT
nidhi@nidhi-Inspiron-5523:~$ cd Desktop
nidhi@nidhi-Inspiron-5523:~/Desktop$ gcc dsa4.c
nidhi@nidhi-Inspiron-5523:~/Desktop$ ./a.out

Enter the no. of customers:9

Enter Name:a

Enter time for transaction:2

Added
Enter Name:b

Enter time for transaction:3

Added
Enter Name:c

Enter time for transaction:1

Added
Enter Name:d

Enter time for transaction:5

Added
Enter Name:e

Enter time for transaction:3

Added
Enter Name:f

Enter time for transaction:2

Added
Enter Name:g

Enter time for transaction:5

Added
Enter Name:h

Enter time for transaction:2

Added
Enter Name:i

Enter time for transaction:4

Added
**********Queue 1***********
Name	R.Time	W.Time
a	2	0
b	3	0
c	1	0
d	5	0
e	3	0

**********Queue 2***********
Name	R.Time	W.Time
f	2	0
g	5	0
h	2	0
i	4	0

---------------------------------------------

---------------------------------------------

**********Queue 1***********
Name	R.Time	W.Time
b	3	0
c	1	0
d	5	0
e	3	0

**********Queue 2***********
Name	R.Time	W.Time
g	5	0
h	2	0
i	4	0

---------------------------------------------

---------------------------------------------

**********Queue 1***********
Name	R.Time	W.Time
c	1	0
d	5	0
e	3	0

**********Queue 2***********
Name	R.Time	W.Time
h	2	0
i	4	0

---------------------------------------------

---------------------------------------------

**********Queue 1***********
Name	R.Time	W.Time
d	5	0
e	3	0

**********Queue 2***********
Name	R.Time	W.Time
i	4	0

---------------------------------------------

---------------------------------------------

**********Queue 1***********
Name	R.Time	W.Time
e	3	0

**********Queue 2***********
Name	R.Time	W.Time

---------------------------------------------

---------------------------------------------

**********Queue 1***********
Name	R.Time	W.Time

**********Queue 2***********
Name	R.Time	W.Time

---------------------------------------------

-----------------------FINAL EVALUATION----------------------

**********Queue 1***********
Name	R.Time	W.Time
a	2	0
b	3	2
c	1	5
d	5	6
e	3	11

**********Queue 2***********
Name	R.Time	W.Time
f	2	0
g	5	2
h	2	7
i	4	9

---------------------------------------------
Total Time of Activity:14
Time Required in Tellers:
Teller	Time
1	14
2	13

---------------------------------------------
*/
