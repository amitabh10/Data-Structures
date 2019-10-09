//Amitabh Saini,SY-E-4
#include<stdio.h>
#include<stdlib.h>
struct n
{
	int data;
	struct n *left,*right;
};
typedef struct n node;
node *stack[20];
int top=-1;
int hl=0,hr=0;
void push(node *p)
{
	if(top==19)
		printf("\nStack Full!\n");
	else
	{
		top++;
		stack[top]=p;
	}
}
int empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
node* pop()
{
	node *p;
	if(!empty())
	{
		p=stack[top];
		top--;
		return p;
	}
	else
	{
		printf("\nStack Empty!\n");
	}
}
node* getnode(int data)
{
	node *p;
	p=malloc(sizeof(node));
	if(p==NULL)
	{
		printf("\nMemory Shortage\n");
		exit(0);
	}
	else
	{
		p->data=data;
		p->left=NULL;
		p->right=NULL;
		return p;
	}
}
void preorder(node *p)
{
	top=-1;
	printf("\n");
	do
	{
		while(p!=NULL)
		{
			printf("%d-",p->data);
			if(p->right!=NULL)
				push(p->right);
			p=p->left;
		}
		if(!empty())
			p=pop();
	}while(!empty() || (p!=NULL));
	printf("null\n");
}
void inorder(node *p)
{
	top=-1;
	printf("\n");
	do
	{
		while(p!=NULL)
		{
			push(p);
			p=p->left;
		}
		if(!empty())
			p=pop();
		printf("%d-",p->data);
		p=p->right;
	}while(!empty() || (p!=NULL));
	printf("null\n");
}
void postorder(node *p)
{
	int a[20],ctr=0,i;
	top=-1;
	printf("\n");
	do
	{
		while(p!=NULL)
		{
			a[ctr]=p->data;
			if(p->left!=NULL)
				push(p->left);
			p=p->right;
			ctr++;
		}
		if(!empty())
			p=pop();
	}while(!empty() || (p!=NULL));
	for(i=ctr-1;i>=0;i--)
		printf("%d-",a[i]);
	printf("null\n");
}

void display(node *p)
{
	int ch;
	do
	{
		printf("\nEnter Choice:\n1.Preorder\n2.Inorder\n3.Postorder\n4.Back\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				preorder(p);
				break;
			case 2:
				inorder(p);
				break;
			case 3:
				postorder(p);
				break;
			case 4:
				break;
			default:
				printf("\nWrong Choice!\n");
				break;
		}
	}while(ch!=4);
}
int height(node *p)
{
	if(p==NULL)
		return 0;	
	if(p->left==NULL && p->right==NULL)
		return 1;
	hl=height(p->left);
	hr=height(p->right);
	if(hl>hr)
		return(hl+1);
	return(hr+1);
}
int getbf(node *p)
{
	int l=0,r=0;
	node *q;
	q=p;
	hl=0,hr=0;
	l=height(q->left);
	hl=0,hr=0;
	r=height(q->right);
	//printf("\nL=%d,R=%d\n",l,r);
	return l-r;
}
node* check(node *root,node *new)
{
	int k,ch,maxk,i=1;
	node *q,*t,*p;
	top=-1;
	do
	{
	printf("\n---Attempt %d---\n",i);
	p=root;
	ch=-1,maxk=0;
	do
	{
		while(p!=NULL)
		{
			k=getbf(p);
			printf("\nBF for %d=%d",p->data,k);
			if(k<-1 || k>1)
			{
				maxk=k;
				t=p;
			}
			if(p->right!=NULL)
				push(p->right);
			p=p->left;
		}
		if(!empty())
			p=pop();
	}while(!empty() || (p!=NULL));
	if(maxk>=-1 && maxk<=1)
		ch=0;
	else
	{
		p=t;
		if(p->data<new->data)
		{
			q=p->right;
			if(q->data<new->data)
			{	
				ch=2;//RR
			}
			else
			{
				ch=4;//RL
			}
		}
		else
		{
			if(p->left->data>new->data)
			{
				q=p->left;
				ch=1;//LL
			}
			else
			{
				q=p->left;
				ch=3;//LR
			}
		}				
	}
	switch(ch)
	{
		case -1:
			printf("Invalid");
			break;
		case 0:
			
			break;
		case 1:
			printf("\nLL ROTATION");
			if(p==root)
			{
				root=q;
				p->left=q->right;
				q->right=p;
			}
			else
			{
				t=root;
				while(t->left!=p && t->right!=p)
				{
					if(p->data<t->data)
						t=t->left;
					else
						t=t->right;
				}
				if(t->left==p)
					t->left=q;
				else
					t->right=q;
				p->left=q->right;
				q->right=p;
			}
			break;
		case 2:
			printf("\nRR ROTATION");
			if(p==root)
			{
				root=q;
				p->right=q->left;
				q->left=p;
			}
			else
			{
				t=root;
				while(t->left!=p && t->right!=p)
				{
					if(p->data<t->data)
						t=t->left;
					else
						t=t->right;
				}
				if(t->left==p)
					t->left=q;
				else
					t->right=q;
				p->right=q->left;
				q->left=p;
			}
			break;
		case 4:
			printf("\nRL ROTATION");
			if(p==root)
			{
				root=new;
				root->right=q;
				root->left=p;
				p->right=NULL;
				q->left=NULL;
			}
			else
			{
				t=root;
				while(t->left!=p && t->right!=p)
				{
					if(p->data<t->data)
						t=t->left;
					else
						t=t->right;
				}
				if(t->left==p)
					t->left=new;
				else
					t->right=new;
				new->right=q;
				new->left=p;
				p->right=NULL;
				q->left=NULL;
			}
			break;
			
		case 3:
			printf("\nLR ROTATION");
			if(p==root)
			{
				root=new;
				root->left=q;
				root->right=p;
				p->left=NULL;
				q->right=NULL;
			}
			else
			{
				t=root;
				while(t->left!=p && t->right!=p)
				{
					if(p->data<t->data)
						t=t->left;
					else
						t=t->right;
				}
				if(t->left==p)
					t->left=new;
				else
					t->right=new;
				
				new->left=q;
				new->right=p;
				p->left=NULL;
				q->right=NULL;
			}
			break;
	}
	preorder(root);
	i++;
	}while(ch!=0);
	return root;
}
node* avl(node *root)
{
	node *p,*new,*q;
	int d,ch;
	do
	{
		printf("\nEnter data:");
		scanf("%d",&d);
		new=getnode(d);
		if(root==NULL)
			root=new;
		else
		{
			p=root;
			while(p!=NULL)
			{
				q=p;
				if(p->data<new->data)
					p=p->right;
				else
					p=p->left;				
			}
			if(q->data<new->data)
				q->right=new;
			else
				q->left=new;
		}
		preorder(root);
		printf("\n-----------Attempting AVL!-----------\n");
		root=check(root,new);
		printf("\n-------------------------------------\n");
		preorder(root);
		printf("\n-------------------------------------\n");
		printf("\nDo you want to add more?(Y(1)/N(0))");
		scanf("%d",&ch);
	}while(ch!=0);
	return root;
}
void simulate()
{
	node *root;
	root=NULL;
	int ch,flag=0,f;
	do
	{
		printf("\n-------AVL TREE--------\n");
		printf("1.Insert\n2.Display\n3.Exit\nEnter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				root=avl(root);
				flag=1;
				break;
			
			case 2:
				if(flag==1)
					display(root);
				else
					printf("\nPlease Input!\n");
				break;
			case 3:
				printf("\nThankyou!\n");
				break;
			default:
				printf("\nWrong Input!\n");
				break;
		}
	}while(ch!=3);
}
void main()
{
	simulate();
}

