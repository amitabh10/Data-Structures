/*AMITABH SAINI,SY-E 4
ASSIGNMENT:WAP to create GLL to store multi variable polynomial.Perform EQUALITY operation on it.*/
#include<stdio.h>
#include<stdlib.h>
typedef union xyz type;
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
typedef struct abc node;
int i=0;
int k=1;
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
	node *temp;
	temp=malloc(sizeof(node));
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
node* generate(char str[])
{
	node *head,*new,*p;
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
				new->a.link=generate(str);
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
	}
	return head;
}
int equal(node* p,node *q)
{
	if(p->flag==q->flag)
	{
		if(p->flag==0)
		{
			if(p->a.data==q->a.data)
			{
				if(p->next!=NULL && q->next!=NULL)
				{
					p=p->next;
					q=q->next;
					k=equal(p,q);
				}
				return k;
			}
			else
				return 0;
		}
		else
		{
			k=equal(p->a.link,q->a.link);
			if(p->next!=NULL && q->next!=NULL)
			{
				p=p->next;
				q=q->next;
				k=equal(p,q);
			}
			return k;	
		}
	}
	else
	{
		return 0;
	}
}
void main()
{
	int res;
	node *p1,*p2;
	p2=NULL;
	char str[100],str1[100];
	printf("Enter the polynomial expression 1:");
	scanf("%s",str);
	p1=generate(str);
	printf("\nThe polynomial expression is:");
	display(p1);
	printf("\n\n");
	printf("Enter the polynomial expression 1:");
	scanf("%s",str1);
	i=0;
	p2=generate(str1);
	printf("\nThe polynomial expression is:");
	display(p2);
	printf("\n");
	res=equal(p1,p2);
	if(res==1)
		printf("\nBoth GLL are equal!\n");
	else
		printf("\nBoth GLL are not equal!\n");
}

