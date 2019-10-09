//itbt & in,pre,post trav
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int lth;
	int rth;
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node n;
n *createnode(int val)
{
	n *temp;
	temp=malloc(sizeof(n));
	if(temp==NULL)
		printf("Memory Shortage!\n");
	else
	{
		temp->lth=1;
		temp->rth=1;
		temp->data=val;
		temp->left=temp;
		temp->right=temp;
		return temp;
	}
}
void inorder(n *head)
{
	n *p;
	p=head->left;
	do
	{
		while(p->lth!=1)
			p=p->left;
		printf("%d->",p->data);
		while(p->rth==1 && p->right!=head)
		{
			p=p->right;
			printf("%d->",p->data);
		}
		p=p->right;
	}while(p!=head);
}
void main()
{
	int d,ch,flag;
	n *p,*new,*head,*root=NULL;
	head=createnode(32767);	
	do{
		printf("\nEnter data:");
		scanf("%d",&d);
		new=createnode(d);
		if(root==NULL)
		{
			root=new;
			root->right=head;
			root->left=head;
			head->left=root;
			head->lth=0;
		}
		else
		{
			flag=0;			
			p=root;
			do{
				if(p->data>new->data)
				{
					if(p->lth==1)
					{
						new->left=p->left;						
						p->left=new;
						p->lth=0;
						new->right=p;
						flag=1;
					}
					else
						p=p->left;
				}
				else
				{
					if(p->rth==1)
					{
						new->right=p->right;
						new->left=p;
						p->right=new;
						p->rth=0;
						flag=1;
					}
					else
						p=p->right;
				}
			}while(flag!=1);
		}
		printf("\nDo you want to add more nodes?(1/0):");
		scanf("%d",&ch);
	}while(ch!=0);
	printf("\nInorder Traversal is:\n");
	inorder(head);
}
