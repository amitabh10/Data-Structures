//GLL-Copy
#include<stdio.h>
#include<stdlib.h>
struct abc
{
	struct abc *next;
	int flag;
	union xyz
	{
		struct abc *link;
		char data;
	}a;
};
int i=0;
typedef struct abc node;
void display(node *q)
{
	while(q!=NULL)
	{
		if(q->flag==0)
		{
			printf("%c,",q->a.data);
		}		
		else
		{
			printf("(");
			display(q->a.link);
			printf(")");			
		}
		q=q->next;	
	}
}
node *accept(int f)
{
	node *q;
	q=malloc(sizeof(node));
	if(q==NULL)
	{
		printf("Memory Shortage!\n");
	}
	else
	{
		q->flag=f;
		q->next=NULL;
		return q;
	}
}
node *copy(node *p)
{
	node *q,*k,*head1;
	head1=NULL;
	while(p!=NULL)
	{
		q=accept(p->flag);
		if(q->flag==0)
		{
			q->a.data=p->a.data;
		}
		else
		{
			q->a.link=copy(p->a.link);
		}
		if(head1==NULL)
			head1=q;
		else
		{
			k=head1;
			while(k->next!=NULL)
				k=k->next;
			k->next=q;	
		}
		p=p->next;
	}
	return head1;
}
node *create(char exp[])
{
	node *head,*new,*p;	
	head=NULL;
	while(exp[i]!='\0' && exp[i]!=')')
	{
		if(exp[i]!=',' && exp[i]!='(')
		{
			new=accept(0);
			new->a.data=exp[i];
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
		else
		{
			if(exp[i]=='(')
			{
				i++;
				new=accept(1);
				new->a.link=create(exp);
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
		}
		i++;
		
	}
	return head;
}
void main()
{
	char exp[50];
	node *c,*d;
	printf("Enter the expression:");
	scanf("%s",exp);
	c=create(exp);
	d=copy(c);
	printf("The COPY GLL is:\n");
	display(d);
	printf("\n");
}
