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
void bubble()
{
	int a[20],i,j,temp;		
	printf("*****Bubble Sort*****\n");
	accept(a);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
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
void selection()
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
void insertion()
{
	int a[20],i,j,t,ctr;
	printf("*****Insertion Sort*****\n");
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
void shell()
{	
	int a[20],i,j,t,f;
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
void bucket()
{	
	int a[20],max=0,i,j,d,k,x,pass=0;
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
void main()
{
	int c;
	while(c!=6)
	{
		printf("Enter Your Choice!\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Shell Sort\n5.Bucket Sort\n6.Exit\n");
		scanf("%d",&c);
		if(c==1)
		{
			bubble();
		}
		else if(c==2)
		{
			selection();
		}
		else if(c==3)
		{
			insertion();
		}
		else if(c==4)
		{
			shell();
		}
		else if(c==5)
		{
			bucket();
		}
		else
		printf("Wrong Choice!\n");
	}
}
