#include<stdio.h>
#include<stdlib.h>
struct list1
{
	int num;
	struct list1 *next;
};

typedef struct list1 list;
int cntr=0;
list *res=NULL;
list *new_node(int num1)
{
	list * temp;
	temp=malloc(sizeof(list));
	temp->num=num1;
	temp->next=NULL;
	return temp;
}

void display(list *head)
{
	
	list *temp;
	temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d -> ",temp->num);
		temp=temp->next;
	}
	printf("null\n");
}

list* quick(list *head,int start,int end)
{
	//printf("\n****Entering Quick***\n");
 	list *q,*p,*temp,*temp1;	
	int k,t,j,i;
	i=0;
	p=head;
	//display(p);
	while(i<start)
	{
		i++;
		p=p->next;
	}
	//printf("\n--p=%d--\n",p->num);
	k=end;
	if(start<end) 
	{  
		q=p->next;
		for(j=start;j<=k-1;j++) 
		{ 
			//printf("\nComparing:%d,%d\n",p->num,q->num);
			if(p->num>q->num) 
			{ 
				if(p==head)
					head=q;
				else
				{
					temp=head;
					temp1=head;
					while(temp->next!=p)
						temp=temp->next;
					while(temp1->next!=q)
						temp1=temp1->next;
					//printf("\n--%d--\n",temp->num);
					temp->next=q;
					//printf("\n--%d--\n",temp->num);
					temp1->next=p;
				}
				p->next=q->next;
				q->next=p;
				p=q->next;
				q=p->next;				 
			} 
			else  
			{
				temp=head;
				temp1=temp->next;
				i=0;
				//printf("\n--%d-%d--\n",k-1,p->num);
				while(i<k-1)
				{
					temp=temp->next;
					temp1=temp1->next;
					i++;
				}
				//printf("\n--%d-%d-%d--\n",k-1,temp->num,temp1->num);
				//scanf("%d",&i);
				if(temp==p)
				{
					continue;
				}	
				else if(temp!=q)
				{
				temp->next=temp1->next;
				temp1->next=q;
				p->next=temp1;
				temp1->next=q->next;
				q->next=temp->next;
				temp->next=q;
				}
				else if(temp==q)
				{
					temp->next=temp1->next;
					temp1->next=q;
					p->next=temp1;
				} 
				q=p->next;
				k--; 
				j--; 
			} 
			printf("\nstatus at %d and start=%d end=%d",j,start,end);
			display(head);
		}
		
		if(start<=k-1)
		{
		//printf("\n*********start:%d,k-1:%d****************\n",start,k-1); 
		head=quick(head,start,k-1);
		//display(head);
		//printf("\n---------------------------------------\n"); 
		}
		if(k<end)
		{
		//printf("\n*********k:%d,end:%d****************\n",k,end);
		head=quick(head,k,end);
		//printf("\n---------------------------------------\n");
		} 
	}
	//printf("\nReturning:\n");
	//display(head);
	return head;
}
void main()
{
	int num,ch,choice;
	list *head,*p,*new,*res;
	head=NULL;
	do
	{
		
		printf("\nEnter element %d of array : ",cntr+1);
		scanf("%d",&num);
		new=new_node(num);
		if(head==NULL)
		{
			head=new;
		}
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new;	
		}
		cntr++;
		printf("\nDo you want to enter more? ( 0 / 1 )");
		scanf("%d",&ch);
	}while(ch!=0);
	display(head);
	res=quick(head,0,cntr-1);
	printf("\nQuick Done\n");
	display(res);
}
