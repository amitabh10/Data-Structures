#include<stdio.h>
#include<math.h>
void heap(int[],int);
void main()
{
	int i,n,j,t,a[10];
	printf("Enter no. of Elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=n-1;i>=0;i--)
	{
		heap(a,i);
		t=a[0];
		a[0]=a[i];
		a[i]=t;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
		
}
void heap(int a[],int n)
{
	int i,j,t,d;
	double pass=log(n+1)/(double)log(2);
	while(pass>0)
	{
		for(i=n;i>0;i-=2)
		{
			d=(i-1)/2;
			if(a[d]<a[i])
			{
				t=a[d];
				a[d]=a[i];
				a[i]=t;
			}
			if((d%2)==0)
			{
				i=i+1;
			}
			else if(a[d]<a[i-1])
			{
				t=a[d];
				a[d]=a[i-1];
				a[i-1]=t;
			}
		}
		pass--;
	}
}
