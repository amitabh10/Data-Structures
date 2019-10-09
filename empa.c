/*ASSIGNMENT 1:-
Arrange the list of employees as per the average of their height and weight by using appropriate sorting method.*/

#include<stdio.h>
#include<string.h>
int n;
struct database
{
	char name[30];
	int ht;
	int wt;
	float avg;
}e[10];
typedef struct database emp;
void sort(emp[]);
void main()
{
	int i,j;
	float sum;
	printf("Enter the no. of employees:\n");
	scanf("%d",&n);
	printf("Enter the details of the employees:\n");
   	for(i=0;i<n;i++)
    	{
		printf("*****Employee %d*****\n",i+1);   
		printf("Enter the name:\n");
        	scanf("%s",e[i].name);
        	printf("Enter the height:\n");
        	scanf("%d",&e[i].ht);
        	printf("Enter the weight:\n");
        	scanf("%d",&e[i].wt);
		sum=e[i].ht+e[i].wt;
		e[i].avg=sum/2;
        }
	sort(e);
}
void display(emp e[])
{	
	int i;
	printf("Arranged list according to the average of their height and weight is:\n");
	printf("NAME\tAVG\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%.2f\n",e[i].name,e[i].avg);
	}
}
void sort(emp e[])
{
	int i,j;
	emp t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(e[i].avg>e[j].avg)
			{
				t=e[i];
				e[i]=e[j];
				e[j]=t;
			}
		}
	}
	display(e);	
}
