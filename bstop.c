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
node* create(node *root)
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
		inorder(root);
		printf("\nDo you want to add more?(Y(1)/N(0))");
		scanf("%d",&ch);
	}while(ch!=0);
	return root;
}
int find(node *p)
{
	int key;
	printf("\nEnter the key:");
	scanf("%d",&key);
	printf("\n");
	while(p!=NULL && p->data!=key)
	{
		if(p->data>key)
			p=p->left;
		else
			p=p->right;
	}
	if(p==NULL)
	{
		return 0;
	}
	return 1;	
}
node* delete(node *p)
{
	node *del,*q,*temp,*root;
	int t;
	root=p;
	q=p;
	printf("\nEnter data to be deleted:");
	scanf("%d",&t);
	del=getnode(t);
	while(p!=NULL && p->data!=del->data)
	{
		q=p;
		if(p->data>del->data)
			p=p->left;
		else
			p=p->right;
	}
	if(p==NULL)
	{
		printf("\nData does not exists!\n");
	}	
	else
	{
		if(p->left==NULL && p->right==NULL)
		{
			if(q->data<p->data)
				q->right=NULL;
			else
				q->left=NULL;
			free(p);
		}
		else if(p->left!=NULL && p->right==NULL)
		{
			if(q->data<p->data)
				q->right=p->left;
			else
				q->left=p->left;
			p->left=NULL;
			free(p);
		}
		else if(p->left==NULL && p->right!=NULL)
		{
			if(q->data<p->data)
				q->right=p->right;
			else
				q->left=p->right;
			p->right=NULL;
			free(p);
		}
		else if(p==root)
		{
			temp=p->right;
			while(temp->left!=NULL)
					temp=temp->left;
			temp->left=p->left;
			root=p->right;
			free(p);
		}
		else
		{
			if(q->data>p->data)
			{
				q->left=p->right;
				temp=p->right;
				while(temp->left!=NULL)
					temp=temp->left;
				temp->left=p->left;
			}
			else
			{
				q->right=p->right;
				temp=p->right;
				while(temp->left!=NULL)
					temp=temp->left;
				temp->left=p->left;
			}
		}
	printf("\nNode Deleted!\nTree After Deletion:");
	inorder(root);
	}
	return root;
}
void simulate()
{
	node *root;
	root=NULL;
	int ch,flag=0,f;
	do
	{
		printf("\n-------TREE--------\n");
		printf("1.Insert\n2.Find\n3.Delete\n4.Display\n5.Exit\nEnter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				root=create(root);
				flag=1;
				break;
			case 2:
				if(flag==1)
				{
					f=find(root);
					if(f!=0)
						printf("\nIt is present!\n");
					else
						printf("\nNot Present!\n");
				}
				else
					printf("\nPlease Input!\n");
				break;
			case 3:
				if(flag==1)
					root=delete(root);
				else
					printf("\nPlease Input!\n");
				break;
			case 4:
				if(flag==1)
					display(root);
				else
					printf("\nPlease Input!\n");
				break;
			case 5:
				printf("\nThankyou!\n");
				break;
			default:
				printf("\nWrong Input!\n");
				break;
		}
	}while(ch!=5);
}
void main()
{
	simulate();
}
/*OUTPUT:
amitabh@amitabh-Inspiron-7537:~$ cd Desktop
amitabh@amitabh-Inspiron-7537:~/Desktop$ gcc d6.c
amitabh@amitabh-Inspiron-7537:~/Desktop$ ./a.out

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:1

Enter data:30

30-null

Do you want to add more?(Y(1)/N(0))1

Enter data:20

20-30-null

Do you want to add more?(Y(1)/N(0))1

Enter data:10

10-20-30-null

Do you want to add more?(Y(1)/N(0))1

Enter data:15

10-15-20-30-null

Do you want to add more?(Y(1)/N(0))1

Enter data:40

10-15-20-30-40-null

Do you want to add more?(Y(1)/N(0))1

Enter data:35

10-15-20-30-35-40-null

Do you want to add more?(Y(1)/N(0))1

Enter data:32

10-15-20-30-32-35-40-null

Do you want to add more?(Y(1)/N(0))1

Enter data:37

10-15-20-30-32-35-37-40-null

Do you want to add more?(Y(1)/N(0))0

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:3

Enter data to be deleted:10

Node Deleted!
Tree After Deletion:
15-20-30-32-35-37-40-null

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:3

Enter data to be deleted:30

Node Deleted!
Tree After Deletion:
15-20-32-35-37-40-null

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:4

Enter Choice:
1.Preorder
2.Inorder
3.Postorder
4.Back
1

40-35-32-20-15-37-null

Enter Choice:
1.Preorder
2.Inorder
3.Postorder
4.Back
4

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:2

Enter the key:30


Not Present!

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:2

Enter the key:40


It is present!

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:3

Enter data to be deleted:35

Node Deleted!
Tree After Deletion:
15-20-32-37-40-null

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:4

Enter Choice:
1.Preorder
2.Inorder
3.Postorder
4.Back
1

40-37-32-20-15-null

Enter Choice:
1.Preorder
2.Inorder
3.Postorder
4.Back
4

-------TREE--------
1.Insert
2.Find
3.Delete
4.Display
5.Exit
Enter Choice:5

Thankyou!
*/
