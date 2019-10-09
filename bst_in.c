#include<stdio.h>
#include<stdlib.h>
struct n
{
	int data;
	struct n *left;
	struct n *right;
};
typedef struct n node;
int top;
node *stk[20];
void push(node *p)
{
	if(top==19)
		printf("Stk Full!\n");
	else
		top++;
		stk[top]=p;
}
node *pop()
{
	node *x;
	if(top==-1)
		printf("Stk empty!\n");
	else
		stk[top]=x;
		top--;
		return x;
}
int stkempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void inorder(node *p)
{
	int top=-1;
	printf("\n");	
	do{
		while(p!=NULL)
		{
			push(p);
			p=p->left;
		}
		if(!stkempty())
			p=pop();
		printf("%d->",p->data);
		p=p->right;
	}while(!stkempty() || p!=NULL);
	printf("null\n");
}
node *createnode(int val)
{
	node *temp;
	temp=malloc(sizeof(node));
	if(temp==NULL)
		printf("Memory Shortage!\n");
	else
	{
		temp->right=NULL;
		temp->left=NULL;
		temp->data=val;
		return temp;
	}
}
void main()
{
	node *root=NULL,*p,*new,*q;
	int d,ch;
	do{
		printf("\nEnter data:");
		scanf("%d",&d);
		new=createnode(d);
		if(root==NULL)
			root=new;
		else
		{
			p=root;
			while(p!=NULL)
			{
				q=p;
				if(p->data>new->data)
					p=p->left;
				else
					p=p->right;
			}
			if(q->data>new->data)
				q->left=new;
			else
				q->right=new;							
		}
		printf("\nMore nodes?(1/0):");
		scanf("%d",&ch);
	}while(ch!=0);
	inorder(root);
}
