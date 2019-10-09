#include<stdio.h>
int a[20],n;
void compute(int b[10][10])
{
	int i,j,ctr=0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(b[i][j]!=0)
			{
				a[ctr]=b[i][j];
				ctr++;
			}
		}
	}
}
void display()
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);	
}
void main()
{
	int max=0,i,j,d,k,x,pass=0;
	int b[10][10];
	printf("Enter no.of elements\n");
	scanf("%d",&n);
	printf("Enter Elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Input End\n");
	for(i=0;i<n;i++)
	{
		if(max<a[i])
			max=a[i];		
	}
	j=max;
	while(j>0)
	{
		j=j/10;
		pass++;		
	}
	j=pass;
	while(j>0)
	{
		for(i=0;i<10;i++)
		{
			for(k=0;k<10;k++)
			b[i][k]=0;
		}
		for(i=0;i<n;i++)
		{
			d=a[i];
			k=pass-j;
				while(k>0)
				{
					d=d/10;
					k--;
				}
				d=d%10;
				for(x=0;x<10;x++)
				{
					if(b[d][x]==0)
					{
					b[d][x]=a[i];
					break;
					}
				}
								
		}
		compute(b);
		j--;
	}
	display();
}

