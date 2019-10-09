#include<stdio.h>
//#include<conio.h>
void main()
{
//clrscr();
int a[100],n,i,beg,end,mid,item;

printf("\n------------ BINARY SEARCH ------------ \n\n");
printf("Enter No. of Elements= ");
scanf("%d",&n);

printf("\nEnter Elements in Sorted Order=\n");
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}

printf("\nEnter Item you want to Search= ");
scanf("%d",&item);

beg=1;
end=n;

mid=(beg+end)/2;                       // Find Mid Location of Array

while(beg<=end && a[mid]!=item)      // Compare Item and Value of Mid
{
if(a[mid]<item)
beg=mid+1;
else
end=mid-1;

mid=(beg+end)/2;
}

if(a[mid]==item)
{
printf("\nData is Found at Location :%d ",mid);
}
else
{
printf("Data is Not Found");
}
}
//getch();
