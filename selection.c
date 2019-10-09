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
	printf("*****Selection Sort*****\n");
	accept(a);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	display(a);
}
