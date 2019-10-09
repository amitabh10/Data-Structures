#include<stdio.h>
#include<stdlib.h>
struct n
{
	int data;
	struct n *next;
};
typedef struct n node;
node *create(int val)
{
	node *temp;
	temp=malloc(sizeof(node));
	if(temp==NULL)
		printf("\nMemory Shortage!");
	else
	{
		temp->data=val;
		temp->next=NULL;
		return temp;
	}
}
int chk(int len)
{
	if(len%2==0)
		return 1;
	else
		return 0;
}
void disp(node *q)
{
	printf("\n");
	while(q!=NULL)
	{
		printf("%d->",q->data);
		q=q->next;
	}
	printf("null\n");
}
void split(int len,node *head)
{
	int l,i,j;	
	node *frnt=NULL,*back=NULL,*p,*q,*new;	
	if(chk(len))
		l=len/2;
	else
		l=(len+1)/2;
	p=head;
	if(len<2)
	{
		new=create(p->data);
		frnt=new;
	}
	else
	{
	for(i=1;i<=l;i++)
	{
		new=create(p->data);
		p=p->next;
		if(frnt==NULL)
			frnt=new;
		else
		{
			q=frnt;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=new;
		}
	}
	while(p!=NULL)
	{
		new=create(p->data);
		p=p->next;
		if(back==NULL)
			back=new;
		else
		{
			q=back;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=new;
		}
	}
	}
	printf("\nFront=\n");
	disp(frnt);
	printf("\nBack=\n");
	disp(back);	
}
void main()
{
	int r,ch,d,ctr=0;
	node *root=NULL,*new,*p;
	do{
		printf("\nEnter data:");
		scanf("%d",&d);
		new=create(d);
		if(root==NULL)
			root=new;
		else
		{
			p=root;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new;
		}
		printf("\nMore nodes?(1/0):");
		scanf("%d",&ch);
		ctr++;
	}while(ch!=0);
	disp(root);
	split(ctr,root);
}

