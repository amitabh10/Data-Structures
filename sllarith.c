//Amitabh Saini,SY-E-4
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct n
{
	int data;
	struct n* next;
};
typedef struct n node;
node* head[3];
node* head1[10];
node* getnode()
{
	node* p;
	p=malloc(sizeof(node));
	if(p==NULL)
	{
		printf("No memory\n");
	}
	else
	{
		return(p);
	}
}
void create(int x,int i)
{
	int d;
	node* new;
	node* p;
	while(x>0)
	{
		d=x%10;
		x=x/10;
		//printf("Value:%d",d);
		new=getnode();
		new->data=d;
		new->next=NULL;
		if(head[i]==NULL)
		{
			head[i]=new;
		}
		else
		{
			p=head[i];
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new;
		}
	}
}
void display(node* p)
{
	printf("\n");
	while(p!=NULL)
	{
		printf("%d -> ",p->data);
		p=p->next;
	}
	printf("null\n");
}
node* rev(node *p)
{
	int c;
	int i;
	node *rev=NULL;
	node *new,*q;
	q=p;
	c=0;
	while(q!=NULL)
	{
		//printf("%d",c);
		c++;
		q=q->next;
	}
	//printf("%d",c);
	while(c>0)
	{
		new=getnode();
		q=p;
		for(i=1;i<c;i++)
		{
			q=q->next;
		}
		new->data=q->data;
		new->next=NULL;
		if(rev==NULL)
		{
			rev=new;
		}
		else
		{
			q=rev;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=new;
		}
		c--;
	}
	display(rev);
	return rev;
}
void accept()
{
	int a,b;
	printf("\nEnter two numbers:\n");
	scanf("%d%d",&a,&b);
	head[0]=NULL;
	head[1]=NULL;
	create(a,0);
	create(b,1);
	printf("\n------SLL 1-------");
	rev(head[0]);
	printf("\n------SLL 2-------");
	rev(head[1]);
}

node* add(node* p,node* q)
{	
	node* r;
	node* new;
	int t=0,k;
	head[3]=NULL;
	r=head[3];
	while(p!=NULL && q!=NULL)
	{
		new=getnode();
		k=p->data+q->data+t;
		t=0;
		while(k>=10)
		{
			k=k-10;
			t++;
		}
		new->data=k;
		new->next=NULL;
		if(head[3]==NULL)
		{
			head[3]=new;
		}
		else
		{
			r=head[3];
			while(r->next!=NULL)
			{
				r=r->next;
			}
			r->next=new;
		}
		p=p->next;
		q=q->next;		
	}
	while(p!=NULL)
	{
		new=getnode();
		k=p->data+t;
		t=0;
		while(k>=10)
		{
			k=k-10;
			t++;
		}
		new->data=k;
		new->next=NULL;
		if(head[3]==NULL)
		{
			head[3]=new;
		}
		else
		{
			r=head[3];
			while(r->next!=NULL)
			{
				r=r->next;
			}
			r->next=new;
		}
		p=p->next;
	}
	while(q!=NULL)
	{
		new=getnode();
		k=q->data+t;
		t=0;
		while(k>=10)
		{
			k=k-10;
			t++;
		}
		new->data=k;
		new->next=NULL;
		if(head[3]==NULL)
		{
			head[3]=new;
		}
		else
		{
			r=head[3];
			while(r->next!=NULL)
			{
				r=r->next;
			}
			r->next=new;
		}
		q=q->next;
	}
	if(t!=0)
	{
		new=getnode();
		new->data=t;
		new->next=NULL;
		if(head[3]==NULL)
		{
			head[3]=new;
		}
		else
		{
			r=head[3];
			while(r->next!=NULL)
			{
				r=r->next;
			}
			r->next=new;
		}
	}
	return head[3];
}
node *sub(node* p,node* q)
{
	node* r;
	node* new;
	int t=0,k;
	head[3]=NULL;
	r=head[3];
	while(p!=NULL && q!=NULL)
	{
		new=getnode();
		if(p->data < q->data && p->next!=NULL)
		{
			k=p->data+10;
			new->data=k-(q->data+t);
			t=1;
		}
		else
		{
			k=p->data;
			new->data=k-(q->data+t);
			t=0;
		}
		new->next=NULL;
		if(head[3]==NULL)
		{
			head[3]=new;
		}
		else
		{
			r=head[3];
			while(r->next!=NULL)
			{
				r=r->next;
			}
			r->next=new;
		}
		p=p->next;
		q=q->next;		
	}
	while(p!=NULL)
	{
		new=getnode();
		if(p->data < t && p->next!=NULL)
		{
			k=p->data+10;
			new->data=k-t;
			t=1;
		}
		else
		{
			k=p->data;
			new->data=k-t;
			t=0;
		}
		new->next=NULL;
		if(head[3]==NULL)
		{
			head[3]=new;
		}
		else
		{
			r=head[3];
			while(r->next!=NULL)
			{
				r=r->next;
			}
			r->next=new;
		}
		p=p->next;
	}
	return head[3];
	
}
void mul(node*t ,node *q)
{
	node* p=t,*new,*r;
	int x=0,ctr=0,j,i,k;
	while(q!=NULL)
	{
		j=ctr;
		head1[ctr]=NULL;
		while(j>0)
		{
			new=getnode();
			new->data=0;
			new->next=NULL;
			if(head1[ctr]==NULL)
			{
				head1[ctr]=new;
			}
			else
			{
				r=head1[ctr];
				while(r->next!=NULL)
				{
					r=r->next;
				}
				r->next=new;
			}
			j--;
		}
		while(p!=NULL)
		{
			new=getnode();
			k=(p->data*q->data)+x;
			x=0;
			while(k>=10)
			{
				k=k-10;
				x++;
			}
			new->data=k;
			new->next=NULL;
			if(head1[ctr]==NULL)
			{
				head1[ctr]=new;
			}
			else
			{
				r=head1[ctr];
				while(r->next!=NULL)
				{
					r=r->next;
				}
				r->next=new;
			}
			p=p->next;
		}
		if(x!=0)
		{
			new=getnode();
			new->data=x;
			new->next=NULL;
			if(head1[ctr]==NULL)
			{
				head1[ctr]=new;
			}
			else
			{
				r=head1[ctr];
				while(r->next!=NULL)
				{
					r=r->next;
				}
				r->next=new;
			}
		}
		p=t;
		x=0;
		q=q->next;
		ctr++;
	}
	/*for(i=0;i<ctr;i++)
	{
		printf("\n----mul%d----\n",i+1);
		display(head1[i]);
	}*/
	if(ctr>1)
	{
		new=add(head1[0],head1[1]);
		for(i=2;i<ctr;i++)
		{
			new=add(new,head1[i]);
		}
		head1[0]=new;
	}
	
}
int compare(node *p,node *q)
{
	int p1=0,q1=0,ctr=0;
	while(p!=NULL && q!=NULL)
	{
		p1=p1+(pow(10,ctr)*(p->data));
		q1=q1+(pow(10,ctr)*(q->data));
		p=p->next;
		q=q->next;
		ctr++;
	}
	if(p!=NULL)
	{
		return 0;
	}
	else if(q!=NULL)
	{
		return 1;
	}
	else
	{
		if(p1>q1)
		return 0;
		else
		return 1;
	}
}
void neg(node *p)
{
	node *q;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	if(p->data!=0)
	{
		p->data= -1 * (p->data);
		//printf("\nNeg:%d",p->data);
	}
	else
	{
		q->data= -1 * (q->data);
		//printf("\nNeg:%d",q->data);
	}
}

void simulate()
{
	int ch,flag=0,c;
	do
	{
		printf("*********Arithmetic Operations************\n1.Input Numbers\n2.Addition\n3.Subtraction\n4.Multiplication\n5.Exit\nEnter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				accept();
				flag=1;
				break;
			case 2:
				if(flag==1)
				{
					add(head[0],head[1]);
					printf("\nAddition:");
					rev(head[3]);
				}
				else
				printf("\nPlease Input Numbers\n");
				break;
			case 3:
				if(flag==1)
				{
					c=compare(head[0],head[1]);
					//printf("%d",c);
					if(c==0)
					{
						sub(head[0],head[1]);
						printf("\nSubtraction:");
						rev(head[3]);
					}
					else
					{
						sub(head[1],head[0]);
						neg(head[3]);
						printf("\nSubtraction:");
						rev(head[3]);	
					}
				}
				else
				printf("\nPlease Input Numbers\n");
				break;
			case 4:
				if(flag==1)
				{
					mul(head[0],head[1]);
					printf("\nMultiplication:");
					rev(head1[0]);
				}
				else
				printf("\nPlease Input Numbers\n");
				break;
			case 5:
				printf("Thankyou!\n");
				break;
			default:
				printf("\nWrong Choice!\n");
				break;
		}
	}while(ch!=5);
}
void main()
{
	simulate();
} 
/*
OUTPUT:

amitabh@amitabh-Inspiron-7537:~$ cd Desktop
amitabh@amitabh-Inspiron-7537:~/Desktop$ gcc ds5.c -lm
amitabh@amitabh-Inspiron-7537:~/Desktop$ ./a.out
*********Arithmetic Operations************
1.Input Numbers
2.Addition
3.Subtraction
4.Multiplication
5.Exit
Enter Choice:1

Enter two numbers:
25
45

------SLL 1-------
2 -> 5 -> null

------SLL 2-------
4 -> 5 -> null
*********Arithmetic Operations************
1.Input Numbers
2.Addition
3.Subtraction
4.Multiplication
5.Exit
Enter Choice:2

Addition:
7 -> 0 -> null
*********Arithmetic Operations************
1.Input Numbers
2.Addition
3.Subtraction
4.Multiplication
5.Exit
Enter Choice:3

Subtraction:
-2 -> 0 -> null
*********Arithmetic Operations************
1.Input Numbers
2.Addition
3.Subtraction
4.Multiplication
5.Exit
Enter Choice:4

Multiplication:
1 -> 1 -> 2 -> 5 -> null
*********Arithmetic Operations************
1.Input Numbers
2.Addition
3.Subtraction
4.Multiplication
5.Exit
Enter Choice:5
Thankyou!
*/


