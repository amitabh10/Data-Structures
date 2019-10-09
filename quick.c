#include<stdio.h>
void quick(int[],int,int);
int size;
void main()
{
	int x[20],i;

  	printf("Enter size of the array: ");
  	scanf("%d",&size);

  	printf("Enter %d elements: ",size);
  	for(i=0;i<size;i++)
    	scanf("%d",&x[i]);
	quick(x,0,size-1);

	printf("\nSorted elements: ");
  	for(i=0;i<size;i++)
    	printf(" \n%d",x[i]);

}
void quick(int a[],int st,int end)
{
	int j,t,k;
	if(st<=end)
	{
			k=end;
			for(j=st;j<=k-1;j++)
			{
				if(a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
				else
				{
					t=a[k];
					a[k]=a[j+1];
					a[j+1]=t;
					k--;
					j--;
				}
			}

			quick(a,st,k-1);
			quick(a,k+1,end);		
	}
}
