#include<stdio.h>
#include<math.h>
void bubble(int[]);
void sel(int[]);
void insert(int[]);
void accept(int[]);
void display(int[]);
void bucket(int[]);
void shell(int[]);
void heap(int[]);
void maxheap(int[],int);
void compute(int[][10],int[]);
int n;
void main()
{
	int ch,flag=0;
	int x[100];
	do
	{
		printf("****SORTING****\n1.Bubble\n2.Selection\n3.Insertion\n4.Bucket\n5.Shell\n6.Heap\n7.Exit\n");
		printf("Enter Choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			bubble(x);
			break;
			case 2:
			sel(x);
			break;
			case 3:
			insert(x);
			break;
			case 4:
			bucket(x);
			break;
			case 5:
			shell(x);
			break;
			case 6:
			heap(x);
			break;
			case 7:
			printf("\nThankyou!\n");
			break;
			default:
			printf("Wrong choice!\n");
			break;
		}
	}while(ch!=7);
}
void heap(int a[])
{
	int i,t;
	accept(a);
	for(i=n-1;i>=0;i--)
	{
		maxheap(a,i);
		t=a[0];
		a[0]=a[i];
		a[i]=t;
	}
	printf("Sorted Array\n");
	display(a);		
}
void maxheap(int a[],int x)
{
	int i,j,t,d;
	double pass=log(x+1)/(double)log(2);
	while(pass>0)
	{
		for(i=x;i>0;i-=2)
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
void compute(int b[10][10],int a[])
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
void check(int b[][10],int d,int t)
{
	int x;
	for(x=0;x<10;x++)
	{
		if(b[d][x]==0)
		{
			b[d][x]=t;
			break;
		}
	}
}
void makezero(int b[][10])
{
	int i,k;
	for(i=0;i<10;i++)
	{
		for(k=0;k<10;k++)
		b[i][k]=0;
	}
}
void bucket(int a[])
{
	int max=0,i,j,d,k,x,pass=0;
	int b[10][10];
	accept(a);
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
		makezero(b);
		k=pass-j;
		for(i=0;i<n;i++)
		{
			d=a[i];
			if(k!=0)
			{
				while(k>0)
				{
					d=d/10;
					k--;
				}
				d=d%10;
				check(b,d,a[i]);
				compute(b,a);
			}
			else
			{
				d=d%10;
				check(b,d,a[i]);
				compute(b,a);
			}						
		}
		j--;
	}
	printf("Sorted Array\n");
	display(a);
}
void insert(int a[])
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
;		display(a);	
	}
	printf("Sorted Array\n");
	display(a);
}
void bubble(int a[])
{
	int i,j,t;
	accept(a);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("Sorted Array\n");
	display(a);		
}
void shell(int a[])
{
	int i,j,t,f;
	accept(a);
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
	printf("Sorted Array\n");
	display(a);	
	}
	else
	{
		printf("Enter hopping frequency greater than n/2\n");
	}
}
void sel(int a[])
{
	int i,j,t;
	accept(a);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("Sorted Array\n");
	display(a);	
}
void accept(int x[])
{
		int i;
		printf("Enter no.of elements\n");
		scanf("%d",&n);
		printf("Enter Elements\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
		}
}
void display(int a[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
