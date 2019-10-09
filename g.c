/*NIDHI SAINI,SY-E 38
ASSIGNMENT:WAP to create GLL to store multi variable polynomial.Perform DEPTH operation on it.*/
#include<stdio.h>
#include<stdlib.h>

struct abc
{
	struct abc *next;
	int flag;
	union xyz
	{
		char data;
		struct abc *link;
	}a;
	
};
typedef struct abc Node;
Node *stack[30];
int top=-1;
int i=0;
int max=0;
int ctr=0;
void display(Node *q)
{
	while(q!=NULL)
	{
		if(q->flag==0)
		{
			printf("%c,",q->a.data);
		}
		else
		{
			ctr++;
			if(max<ctr)
				max=ctr;
			printf("(");
			display(q->a.link);
			ctr--;
			printf(")");
		}
		q=q->next;
	}
}

Node *pop()
{
	return(stack[top--]);
}

void push(Node *p)
{
	stack[++top]=p;
}

int stackempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void depth(Node *p)
{
	int max1=0;
	int cntr=0;
	do
	{
		if(p==NULL)
		{	
			p=pop(); 
			cntr--;
		}
		if(p->flag==0)
		{
			p=p->next;
		}
		else
		{
			if(p->next!=NULL)			
				push(p->next);
			cntr++;
			if(max1<cntr)
				max1=cntr;
			p=p->a.link;
		}

	}while((p!=NULL) || (!stackempty()));
	printf("\nDepth = %d ",max1+1);
}
Node *accept(int f)
{
	Node *temp;
	temp=malloc(sizeof(Node));
	if(temp==NULL)
	{
		printf("\nMemory Shortage!");
	}
	else
	{
		temp->flag=f;
		temp->next=NULL;
		return temp;
	}
}
Node *generate(char str[])
{
	Node *head,*new,*p;
	head=NULL;
	while(str[i]!='\0' && str[i]!=')')
	{
		if(str[i]!=',' && str[i]!='(')
		{
			new=accept(0);
			new->a.data=str[i];
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
		}
		else
		{
			if(str[i]=='(')
			{
				i++;
				new=accept(1);
				//printf("\nRec Start\n");
				new->a.link=generate(str);
				//printf("\nRec End\n");
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
			}
		}
		i++;
		//printf("\n");
		//display(head);
	}
	return head;
}
void main()
{
	Node *p;
	char str[100];
	printf("Enter the polynomial expression:");
	scanf("%s",str);
	p=generate(str);
	printf("\nThe polynomial expression is:");
	display(p);
	printf("\n");
	printf("\nDepth:%d\n",max+1);
	depth(p);
}
/*OUTPUT:
nidhi@nidhi-Inspiron-5523:~$ cd Desktop/sem4/DSLab
nidhi@nidhi-Inspiron-5523:~/Desktop/sem4/DSLab$ gcc gll_d.c
nidhi@nidhi-Inspiron-5523:~/Desktop/sem4/DSLab$ ./a.out
Enter the polynomial expression:a,(b,c,(d,((e),f),(g),h),i),j,(k)

The polynomial expression is:a,(b,c,(d,((e,)f,)(g,)h,)i,)j,(k,)

Depth:5
nidhi@nidhi-Inspiron-5523:~/Desktop/sem4/DSLab$ */
