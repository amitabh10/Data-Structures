/*You have a fleet of N cars waiting for repair, with the estimated repair times rk for the car Ci , 1 < k < N. What is the best repairschedule (order of repairs) to minimize the total lost time forbeing out­of­service. How much computation is needed to find the lost service­times all schedules?*/

#include<stdio.h>
#include<stdlib.h>
struct car
{
	char name[30];
	int wait;
	int lost;
};
typedef struct car c;
c a[10];
int n,r=5;
void disp(c b[])
{
	int i;	
	printf("\nOrder of repairs should be:\n");
	printf("Sr No\t Car\t Repair\t Lost time\n");
	for(i=0;i<n;i++)
	{
		if(i==1)
			a[i].lost=a[i].wait+a[i-1].wait;
		else if(i>1)
			a[i].lost=a[i-1].lost+a[i].wait;
		printf("%d\t %s\t %d\t %ds\n",i+1,a[i].name,a[i].wait,a[i].lost);
	}
	printf("\nTotal lost time=%ds\n",a[n-1].lost);
} 
void insertion()
{
	int ctr,k,j,i;
	c t;	
	for(i=0;i<n;i++)
		a[i].wait=0;	
	for(i=0;i<n;i++)
	{
		printf("\n*****Details of Car %d*****\n",i+1);
		printf("Name:\n");
		scanf("%s",t.name);
		printf("Repair time(k<%d):\n",n);
		scanf("%d",&k);
		t.wait=r*k;
		ctr=0;
		for(j=0;j<i;j++)
		{
			if(t.wait>a[j].wait)
			{
				ctr++;
			}
		}
		for(j=n-1;j>ctr;j--)
			a[j]=a[j-1];
		a[ctr]=t;
	}
	disp(a);
}
void main()
{
	printf("\nEnter the no. of cars:\n");
	scanf("%d",&n);
	insertion();
}
