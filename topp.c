/*WAP using trees,to assign roll nos. to students according to their prev yrs marks.(i.e the topper will be roll no.1)*/
#include<stdio.h>
#include<stdlib.h>
# define max 50
struct bst
{
	int data;
	char name[20];
	struct bst *left,*right;
};
typedef struct bst Node;
Node* arr[20];
Node* stack[50];
int ctr=0;
int top=-1;
void push(Node *p)
{
	if(top==max-1)
	{
		printf("Stack is full\n");
		exit(0);
	}
	else
	{
		top++;
		stack[top]=p;
	}
}
Node* pop()
{
	Node *t;
	if(top!=-1)
	{
		t=stack[top];
		top--;
		return t;
	}
}
void inorder(Node *q)
{
	do
	{
		while(q!=NULL)
		{
			push(q);
			q=q->left;
		}
		if(top!=-1)
		{
			q=pop();
		}
		arr[ctr]=q;
		ctr++;
		q=q->right;
	}while(top!=-1 || q!=NULL);
}

Node *create()
{
	Node *temp;
	temp=malloc(sizeof(Node));
	if(temp==NULL)
	{
		printf("Memory Shortage!\n");
	}
	else
	{
		printf("Enter Name: ");
		scanf("%s",temp->name);
		printf("Enter Marks:");
		scanf("%d",&temp->data);
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
}
Node *insert()
{
	Node *root=NULL,*p,*new;
	int c,flag=0;
	do
	{		
		new=create();
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
				if(p->data>new->data)
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
		printf("Do you want to continue to add details?(0/1)");
		scanf("%d",&c);
	}while(c==1);
	return root;
}

void main()
{
	int i;
	Node *root,*p;
	root=insert();
	inorder(root);
	printf("\n_________________________________________\n");
	for(i=ctr-1;i>=0;i--)
	{
		printf("\nRoll no:-%d\n",ctr-i);
		printf("Name:%s\n",arr[i]->name);
		printf("Marks:%d\n",arr[i]->data);
	}
	printf("_________________________________________\n");
	
}
