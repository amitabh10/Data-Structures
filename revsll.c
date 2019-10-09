
/*Write an iterative Reverse() function that reverses a list by rearranging all the .next pointers and the head pointer. Ideally, Reverse() should only need to make one pass of the list.*/
#include<stdio.h>
#include<stdlib.h>
struct stud
{
	int no;
	struct stud *next;
};
typedef struct stud node;
node* stack[20];
node *h=NULL,*re=NULL;
int top=-1;
node *accept()
{
	node *p;
	p=malloc(sizeof(node));
	if(p==NULL)
	{
		printf("Shortage of memory\n");
	}
	else
	{
		p->next=NULL;
		return(p);
	}
}

void display(node *p)
{
	printf("\n");
	while(p!=NULL)
	{
		printf("%d -> ",p->no);
		p=p->next;
	}
	printf("null\n");
}
node* copy(node *p)
{
	node *q,*head,*new;
	head=NULL;
	while(p!=NULL)
	{
		new=accept();
		new->no=p->no;
		if(head==NULL)
			head=new;
		else
		{
			q=head;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=new;
		}
		p=p->next;
	}
	return head;
}
void rev(node *head)
{
	node *n;
	node *p=NULL;
	node *c=copy(head);
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	printf("\nThe list in reverse order:\n");
	display(p);
		
}
node* rev1(node *head)
{
	node *n;
	if(head!=NULL)
	{
		n=head->next;
		head->next=re;
		re=head;
		head=n;
		rev1(head);
	}
	else
	{
		return re;
	}	
}
void push(node *p)
{
	if(top==19)
	{
		printf("Stack full!");
	}
	else
	{
		top++;
		stack[top]=p;
	}
}
node* pop()
{
	node *t;
	if(top!=-1)
	{
		t=stack[top];
		top--;
		return t;
	}
}	
void rev2(node *p)
{
	int i,ctr=0;
	node *new,*head,*t;
	node *q=p;
	head=NULL;
	while(q!=NULL)
	{
		push(q);
		q=q->next;
		ctr++;		
	}
	for(i=0;i<ctr;i++)
	{
		new=accept();
		t=pop();
		new->no=t->no;
		if(head==NULL)
			head=new;
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new;
		}
	}
	printf("\nThe list in reverse order:\n");
	display(head);
}
void rev3(node *p)
{
	int ctr=0,i;
	node *new,*q,*head;
	q=p;
	printf("\n");
	head=NULL;
	while(q!=NULL)
	{
		q=q->next;
		ctr++;		
	}
	//printf("null\n");
	while(ctr>0)
	{
		q=p;
		for(i=1;i<ctr;i++)
		{
			q=q->next;
		}
		new=accept();
		new->no=q->no;
		if(head==NULL)
			head=new;
		else
		{
			q=head;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=new;
		}
		ctr--;
	}
	printf("\nThe list in reverse order:\n");
	display(head);
}	
void main()
{
	node *p,*new,*head,*r;
	int ch,c;
	head=NULL;
	do
	{
		new=accept();
		printf("Enter the number\n");
		scanf("%d",&new->no);
		if(head==NULL)
			head=new;
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new;
		}
		printf("Do you want to continue?(0/1) ");
		scanf("%d",&ch);
	}while(ch==1);
	printf("The list in original order:\n");
	display(head);
	do	
	{
		printf("---Enter Your Choice---\n");
		printf("1)Strategy 1(Using pointers)\n2)Strategy 2(Using recurrsive function)\n3)Strategy 3(Using stack)\n4)Strategy 4(Using counter)\n5)Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				rev(head);
				break;
			case 2:
				r=rev1(copy(head));
				display(r);
				break;
			case 3:
				rev2(head);
				break;
			case 4:
				rev3(head);
				break;
			case 5:
				printf("THANK YOU\n");
				break;
			default:
				printf("WRONG INPUT!\n");
				break;
		}
	}while(c!=5);
}
/*
OUTPUT:

Enter the number
1
Do you want to continue?(0/1) 1
Enter the number
2
Do you want to continue?(0/1) 1
Enter the number
3
Do you want to continue?(0/1) 1
Enter the number
4
Do you want to continue?(0/1) 1
Enter the number
5
Do you want to continue?(0/1) 0
The list in original order:

1 -> 2 -> 3 -> 4 -> 5 -> null
---Enter Your Choice---
1)Strategy 1(Using pointers)
2)Strategy 2(Using recurrsive function)
3)Strategy 3(Using stack)
4)Strategy 4(Using counter)
5)Exit
1

The list in reverse order:

5 -> 4 -> 3 -> 2 -> 1 -> null
---Enter Your Choice---
1)Strategy 1(Using pointers)
2)Strategy 2(Using recurrsive function)
3)Strategy 3(Using stack)
4)Strategy 4(Using counter)
5)Exit
2

5 -> 4 -> 3 -> 2 -> 1 -> null
---Enter Your Choice---
1)Strategy 1(Using pointers)
2)Strategy 2(Using recurrsive function)
3)Strategy 3(Using stack)
4)Strategy 4(Using counter)
5)Exit
3

The list in reverse order:

5 -> 4 -> 3 -> 2 -> 1 -> null
---Enter Your Choice---
1)Strategy 1(Using pointers)
2)Strategy 2(Using recurrsive function)
3)Strategy 3(Using stack)
4)Strategy 4(Using counter)
5)Exit
4


The list in reverse order:

5 -> 4 -> 3 -> 2 -> 1 -> null
---Enter Your Choice---
1)Strategy 1(Using pointers)
2)Strategy 2(Using recurrsive function)
3)Strategy 3(Using stack)
4)Strategy 4(Using counter)
5)Exit
5
THANK YOU
*/
