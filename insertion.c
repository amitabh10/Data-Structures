#include<stdio.h>
int n,a[20];
void display(int x[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",x[i]);
	}
}
void main()
{
	int i,j,t,ctr;
	printf("Enter no. of Elements\n");
	scanf("%d",&n);
	printf("Enter %d numbers\n",n);
	for(i=0;i<n;i++)
	{
		a[i]=0;
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter:");
		scanf("%d",&t);
		ctr=0;
		for(j=0;j<i;j++)
		{
			if(t>a[j])
			ctr++;
		}
		for(j=n-1;j>ctr;j--)
		{
			a[j]=a[j-1];
		}
		a[ctr]=t;
		printf("\nCurrent Array:\n");
		display(a);	
	}
	printf("Sorted Array\n");
	display(a);
}
