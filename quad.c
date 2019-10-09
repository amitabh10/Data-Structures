/*
WAP to store k keys into an arrray of size n at location computed using a hash function, loc= key / n, where k<=n and k takes values  from [1 to m], m>n. To handle the collisions use the following collision resolution techniques .
	a. Linear probing with chaining with replacement
	b. Quadratic probing technique
*/
#include<stdio.h>
int hash(int );
void lpcr();
void qp();
void initialize();
void display();
int array[100][2];
int k;	
int main()
{
	int choice;
	printf("\nEnter the number of keys k (k <= 100) : ");
	scanf("%d",&k);
	do
	{
		printf("\nWhich technique do you wish to apply ?");
		printf("\n1.Linear probing with chaining with replacement \n2.Quadratic probing technique \n3.Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: initialize();
					lpcr();
					display(array);
					break;
			case 2: initialize();
					qp();
					display(array);
					break;
			case 3: break;
		}
	}
	while(choice!=3);	
	return 0;
}
void initialize()
{
	int y,z;
	for(y=0;y<100;y++)
	{
		for(z=0;z<2;z++)
		{
			array[y][z]=0;
		}
	}
	
}
void lpcr()
{
	int q=0,temp1,temp2,location,temp,i,j,templ;
	for(i=0;i<k;i++)
	{
		printf("\nEnter key %d : ",i+1);
		scanf("%d",&temp);
		location=hash(temp);
		if(array[location][0]==0)
		{
				array[location][0]=temp;
		}
		else
		{
			if(hash(array[location][0])==location)
			{
				temp1=array[location][1];
			
				while(temp1!=0)
				{
					temp1=array[temp1][1];
				}
				 //temp 1 contains the row where link is zero and after lp i need to put the link of the element m adding at the link of temp1 row
				temp2=temp1;
				while(array[temp2][0]!=0)
				{
					temp2++;
				}
				array[temp2][0]=temp;
				array[temp1][1]=temp2;
				
			}
			else
			{
				temp1=array[location][0];
				templ=array[location][1];
				array[location][0]=temp;
				for(i=0;i<100;i++)
				{
					if(array[i][1]==location)
						break;
				}
				j=i;
				while(array[j][0]!=0)
				{
					j++;
				}
				array[j][0]=temp1;
				array[j][1]=templ;
				array[i][1]=j;
			
				
				
			}
		}
		display();
	}
	
}
void qp()
{
	int q=0,temp1,i,temp,location;	
	printf("\nQuadratic probing!");
	printf("\n%d\n",i);
	for(i=0;i<k;i++)
	{
		printf("\nEnter key %d : ",i+1);
		scanf("%d",&temp);
		location=hash(temp);
		if(array[location]==0)
		{
			array[location][0]=temp;
		}
		else
		{
			temp1=location;
			while(array[temp1][0]!=0)
			{
				temp1=temp1+(q*q);
				q++;
			}
			array[temp1][0]=temp;
		}

	}
}
int hash(int x)
{
	int loc;
	loc= x/100;
	return loc;
}	

void display()
{
	int j;
	printf("\nIndex\tKey value\t Links");
	for(j=0;j<10;j++)
	{
		printf("\n%d\t%d\t%d",j+1,array[j+1][0],array[j+1][1]);
	}
	
}
