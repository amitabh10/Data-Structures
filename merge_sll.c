#include<stdio.h>
#include<stdlib.h>
struct list1
{
	int num;
	struct list1 *next;
	struct list1 *prev; 
};

typedef struct list1 list;
int cntr=0;
list *new_node(int num1)
{
	list * temp;
	temp=malloc(sizeof(list));
	temp->num=num1;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

void display(list *head)
{
	
	list *temp;
	temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->num);
		temp=temp->next;
	}
}

void bubble(list *head)
{

	printf("\nCntr : %d",cntr);
	printf("\nInside bubble sort : \n");
	list *p,*q;
	int i=0,j=0,temp,x;
	x=cntr;
	for(i=0;i<x-1;i++)
	{
		p=head;
		q=p->next;
		//printf("\nEntering Nest\n");
		for(j=0;j<x-1;j++)
		{
			//printf("\n--Comparing %d and %d--\n",p->num,q->num);
			if(p->num>q->num)
			{
				if(p->prev==NULL)
				{
					head=q;	
				}
				else
				{
					p->prev->next=q;
					if(q->next!=NULL)
						q->next->prev=p;
				}
				p->next=q->next;
				q->prev=p->prev;
				q->next=p;
				p->prev=q;
				p=q->next;
				q=p->next;
			}
			else
			{
				p=p->next;
				q=q->next;
			}
			//display(head);
		}
	}
	display(head);	
}
list* mergemech(list *l,list *r,list *res)
{
	list *p,*q,*new,*t;
	int nl=0,nr=0,i=0,j=0,k=0;
	res=NULL;
	p=l;
	while(p!=NULL)
	{
		nl++;
		p=p->next;
	}
	q=r;
	while(q!=NULL)
	{
		nr++;
		q=q->next;
	}
	p=l;
	q=r;
	while(i<nl && j<nr)
	{
		if(p->num<=q->num)
		{
			new=new_node(p->num);
			if(res==NULL)
			{
				res=new;
			}
			else
			{
				t=res;
				while(t->next!=NULL)
				{
					t=t->next;
				}
				t->next=new;
				new->prev=t;	
			}
			p=p->next;
			i++;	
		}
		else
		{
			new=new_node(q->num);
			if(res==NULL)
			{
				res=new;
			}
			else
			{
				t=res;
				while(t->next!=NULL)
				{
					t=t->next;
				}
				t->next=new;
				new->prev=t;	
			}
			q=q->next;
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		new=new_node(p->num);
		if(res==NULL)
		{
			res=new;
		}
		else
		{
			t=res;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=new;
			new->prev=t;	
		}
		p=p->next;
		i++;
		k++;
	}
	while(j<nr)
	{
		new=new_node(q->num);
		if(res==NULL)
		{
			res=new;
		}
		else
		{
			t=res;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=new;
			new->prev=t;	
		}
		q=q->next;
		j++;
		k++;
	}
	return res;
}
list* merge(list *head)
{
	int n=0,mid,i;
	list *p,*q,*l,*r,*new,*lhead,*rhead;
	p=head;
	lhead=NULL;
	rhead=NULL;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	if(n<2)
	{
		return head;
	}
	mid=n/2;
	p=head;
	for(i=0;i<mid;i++)
	{
		new=new_node(p->num);
		if(lhead==NULL)
		{
			lhead=new;
		}
		else
		{
			q=lhead;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=new;
			new->prev=q;	
		}
		p=p->next;		
	}
	//display(lhead);
	while(p!=NULL)
	{
		new=new_node(p->num);
		if(rhead==NULL)
		{
			rhead=new;
		}
		else
		{
			q=rhead;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=new;
			new->prev=q;	
		}
		p=p->next;		
	}
	//display(rhead);
	lhead=merge(lhead);
	rhead=merge(rhead);
	return mergemech(lhead,rhead,head);
}
void quick(list *head,int start,int end)
{
	
 	list *temp,*p;	
	int k,t,j,x;
	temp=head;
	x=0;	
	if(start<=end) 
	{ 
		k=end; 
		while(x!=start)
		{
			temp=temp->next;
			x++;
		}
		for(j=start;j<=k-1;j++) 
		{ 
			if(temp->num>temp->next->num) 
			{ 
				t=temp->num; 
				temp->num=temp->next->num; 
				temp->next->num=t;
				temp=temp->next;
			} 
			else 
			{
				p=temp;
				while(p->next!=NULL)
				{
					p=p->next;
				} 
				t=p->num;
				p->num=temp->num; 
				temp->num=t;
				k--; 
				j--;
				temp=temp->next; 
			} 
			printf("\nstatus at %d and start=%d end=%d",j,start,end);
			display(head);
		} 
		quick(head,start,k-1); 
		quick(head,k+1,end); 
	} 

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
			new->prev=p;	
		}
		cntr++;
		printf("\nDo you want to enter more? ( 0 / 1 )");
		scanf("%d",&ch);
	}while(ch!=0);
	
	display(head);
	do
	{
		printf("\n1. Bubble Sort\n2. Merge Sort\n3.Quick Sort\n4. Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: bubble(head);
				break;
			case 2: res=merge(head);
				printf("\nSorted by merge sort : \n");
				display(res);					
				break;
			case 3: quick(head,0,cntr-1);
				printf("\nSorted by quick sort : \n");
				display(head);					
				break;
			case 4: break;
			default: printf("\nWrong choice");
				break;
		}
		
	}while(choice!=4);

}
