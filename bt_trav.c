//Write a Program to create a Binary Tree and perform following nonrecursive operations on it. a. Preorder Traversal b. Postorder Traversal c. Count total no. of nodes d. Display height of a tree.
#include<stdio.h>
#include<stdlib.h>
#define max 50
int top=-1;
struct abc 
{
	int data;
	struct abc *left,*right;
};
typedef struct abc tree;
tree *stk[max];
tree *create(int elem)
{
	tree *temp;
	temp=malloc(sizeof(tree));
	if(temp==NULL)
	{
		printf("Memory Shortage!\n");
	}
	else
	{
		temp->data=elem;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
}
int empty()
{
	if(top==-1)
	{
		//printf("Stack Empty!");
		return 1;
	}
	else
		return 0;
}
void push(tree *y)
{
	if(top==(max-1))
	{
		//printf("Stack Full!");
	}
	else
	{
		top++;
		//printf("Pushing %d\n",y->data);
		stk[top]=y;
	}
}
tree *pop()
{
	tree *x;
	if(top==-1)
	{
		//printf("Stack Empty!");
	}
	else
	{
		x=stk[top];
		//printf("Popping %d\n",x->data);
		top--;
		return x;
	}
}
/*void inorder(tree *t)
{
	int s;	
	do{
		while(t!=NULL)
		{
			push(t);
			t=t->left;
		}
		t=pop();
		printf("%d-",t->data);
		t=t->right;
		s=empty();
	}while(s!=1 && t!=NULL);
}*/
void postorder(tree *t)
{
	int s,i=0,a[50],ctr=0,j;	
	//printf("Preorder sequence is:\n");
	while(t!=NULL)
	{
		a[i]=t->data;
		i++;
		ctr++;
		push(t);
		t=t->right;
	}
	do
	{
		t=pop();
		t=t->left;
		while(t!=NULL)
		{
			a[i]=t->data;
			i++;
			ctr++;
			push(t);
			t=t->right;
		}
		s=empty();
	}while(s!=1);
	for(j=ctr-1;j>=0;j--)
	{
		printf("%d-",a[j]);
	}
	printf("end\b");
	printf("\nTraversal is finished!\n");
	
}
void display(tree *q)
{
	if(q!=NULL)
	{
		display(q->left);		
		printf("%d-",q->data);
		display(q->right);
	}
}
void preorder(tree *p)
{	
	int s;
	printf("Preorder sequence is:\n");
	do
	{
		while(p!=NULL)
		{
			printf("%d-",p->data);
			if(p->right!=NULL)
				push(p->right);
			p=p->left;
		}
		s=empty();
		if(s==0)
			p=pop();
	}while(!empty() || (p!=NULL));
	printf("end");
}
/*void preorder(tree *t)
{
	int s;	
	printf("Preorder sequence is:\n");
	while(t!=NULL)
	{
		printf("%d-",t->data);
		push(t);
		t=t->left;
	}
	do
	{
		t=pop();
		t=t->right;
		while(t!=NULL)
		{
			printf("%d-",t->data);
			push(t);
			t=t->left;
		}
		s=empty();
	}while(s!=1);
	printf("end\b");
	printf("\nTraversal is finished!\n");
	
}*/
tree *insert()
{
	tree *root=NULL,*p,*new;
	int n,k,c,flag=0;
	do{
		printf("Enter data:");
		scanf("%d",&n);
		new=create(n);
		if(root==NULL)
		{
			root=new;
		}
		else
		{
			p=root;
			do
			{
				flag=0;
				printf("\nEnter L/R of %d?(L=1 and R=0):",p->data);
				scanf("%d",&k);
				if(k==1)
				{
					if(p->left==NULL)
					{
						p->left=new;
						flag=1;
					}
					else
					{
						p=p->left;
					}
				}
				else
				{
					if(p->right==NULL)
					{
						p->right=new;
						flag=1;
					}
					else
					{
						p=p->right;
					}
				}
					
			}while(flag!=1);
		}
		display(root);
		printf("\nDo you want to add more nodes?(Y=1/N=0):");
		scanf("%d",&c);
	}while(c!=0);
	display(root);
	printf("\n");
	return root;
}
void main()
{
	tree *t;
	int ch;	
	t=insert();
	do{
		printf("\nEnter your choice:\n1.Preorder Traversal\n2.Postorder Traversal\n3.Count total no. of nodes\n4.Display height of a tree\n5.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			preorder(t);
		}
		if(ch==2)
		{
			postorder(t);
		}
	}while(ch!=5);
}
