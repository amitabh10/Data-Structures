#include<stdio.h>
int n;
void accept(int x[])
{	
	int i;
	printf("Enter the no. of elements you want to sort:");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
}
void display(int x[])
{	
	int i;
	printf("The sorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",x[i]);
	}
}
void main()
{
	int a[20],i,j,temp;		
	printf("*****Bubble Sort*****\n");
	accept(a);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	display(a);
}
