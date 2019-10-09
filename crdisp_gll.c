#include<stdio.h>
struct abc
{
	struct abc *next,*link;
	int flag;
	char data;
};
typedef struct abc Node;
void main()
{
	Node *head=Null;
	Node *new,*p,*q,*s;
	char str[10];
	int i=0;
	gets(str);
	p=generate(str);
	printf("\nThankyou");
}
Node *generate(char *str)
{
	head=Null;
	while(str[i]!='\0' && str[i]!=')')
	{
		if(str[i]!=',' && str[i]!='(')
		{
			new=accept(str[i],0);
			if(head==Null)
				head=new;
			else
			{
				p=head;
				while(p->next!=Null)
				{
					p=p->next;
				}
				p->next=new;
			}
		}
		else
		{
			i++;
			if(str[i]=='(')
			{
				i++;
				s=accept(#,1);
				s->link=generate(str+i);
			}
		}
	}
	q=display(p);
	return q;
}
Node *accept(char d,int f)
{
	Node *p;
	p=(Node *)malloc(sizeof(Node));
	p->data=d;
	p->flag=f;
	p->next=Null;
}
Node *display(Node *q)
{
	while(q!=Null)
	{
		if(q->flag==0)
		{
			printf("%c,",q->data);
		}
		else
		{
			printf("(");
			display(q->link);
		}
		q=q->next;
	}
	printf(")");
}
