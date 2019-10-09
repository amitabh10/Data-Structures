#include<stdio.h>
void main()
{
	int i,j,t,n,f,a[10];
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter Elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter hopping frequency\n");
	scanf("%d",&f);
	if(f>n/2)
	{
		while(f>0)
		{
			for(i=0;i<n-f;i++)
			{
				if(a[i]>a[i+f])
				{
					t=a[i];
					a[i]=a[i+f];
					a[i+f]=t;
				}
			}
			f--;
		}	
	}
	else
	{
		printf("Enter hopping frequency greater than n/2");
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}		
}
