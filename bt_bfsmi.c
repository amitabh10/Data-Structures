//Write a Program to create a Binary Tree and perform following nonrecursive operations:1.Levelwise Display 2.Mirror Image 3.Height of Tree.
#include<stdio.h>
#include<stdlib.h>
#define max1 20
struct abc 
{
	int data;
	struct abc *left,*right;
};
typedef struct abc tree;
tree *q[max1];
int front,rear,max=1;
void display(tree *q)
{
	if(q!=NULL)
	{
		display(q->left);		
		printf("%d-",q->data);
		display(q->right);
	}
}
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
	//printf("In empty");
	if(rear-front==-1)
		return 1;
	else
		return 0;
}
void addq(tree *t)
{
	if(rear==max1-1)
	{
		printf("\nQueue Full\n");
	}
	else
	{
		rear++;
		q[rear]=t;
		//printf("\nAdded in Queue:%d\n",q[rear]->data);
	}
}
tree *delete()
{
	tree *x;
	if(rear-front==-1)
		printf("Queue is Empty!\n");
	else
	{
		x=q[front];
		//printf("Deleting %d",x->data);
		front++;
		return x;
	}
}
void bfs(tree *p,int flag)
{
	rear=-1;
	front=0;
	addq(p);
	if(flag==0)
		printf("BFS Traversal is:\n");
	else
		printf("Mirror Image is:\n");
	while(!empty())  //!QueueEmpty
	{
		p=delete();
		printf("%d-",p->data);
		if(p->left!=NULL)
			addq(p->left);
		if(p->right!=NULL)
			addq(p->right);
	}
	printf("end\n");
}
void mirror(tree *p)
{
	rear=-1;
	front=0;
	tree *temp;
	tree *root=p;
	addq(p);
	while(!empty())  //!QueueEmpty
	{
		p=delete();
		temp=p->left;
		p->left=p->right;
		p->right=temp;
		if(p->left!=NULL)
			addq(p->left);
		if(p->right!=NULL)
			addq(p->right);
	}
	bfs(root,1);
}
void ht(tree *p,int l)
{
	if(p!=NULL)
	{
		//printf("Value of l=%d max=%d",l,max);
		if(max<l)
		{
			max=l;
		}
		ht(p->left,l+1);
		ht(p->right,l+1);
	}
}
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
		printf("\nEnter your choice:\n1.Levelwise Display\n2.Mirror Image\n3.Display height of a tree\n4.Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			bfs(t,0);
		}
		if(ch==2)
		{
			mirror(t);
		}
		if(ch==3)
		{
			ht(t,1);
			printf("\nHeight of the tree is:%d\n",max);
		}
	}while(ch!=4);
}
/*//OUTPUT:
nidhi@nidhi-Inspiron-5523:~$ cd Desktop
nidhi@nidhi-Inspiron-5523:~/Desktop$ gcc bt_bfsmi.c
nidhi@nidhi-Inspiron-5523:~/Desktop$ ./a.out
Enter data:50
50-
Do you want to add more nodes?(Y=1/N=0):1
Enter data:40

Enter L/R of 50?(L=1 and R=0):1
40-50-
Do you want to add more nodes?(Y=1/N=0):1
Enter data:60

Enter L/R of 50?(L=1 and R=0):0
40-50-60-
Do you want to add more nodes?(Y=1/N=0):1
Enter data:30

Enter L/R of 50?(L=1 and R=0):1

Enter L/R of 40?(L=1 and R=0):1
30-40-50-60-
Do you want to add more nodes?(Y=1/N=0):1
Enter data:45

Enter L/R of 50?(L=1 and R=0):1

Enter L/R of 40?(L=1 and R=0):0
30-40-45-50-60-
Do you want to add more nodes?(Y=1/N=0):1
Enter data:55

Enter L/R of 50?(L=1 and R=0):0

Enter L/R of 60?(L=1 and R=0):1
30-40-45-50-55-60-
Do you want to add more nodes?(Y=1/N=0):1
Enter data:70

Enter L/R of 50?(L=1 and R=0):0

Enter L/R of 60?(L=1 and R=0):0
30-40-45-50-55-60-70-
Do you want to add more nodes?(Y=1/N=0):0
30-40-45-50-55-60-70-

Enter your choice:
1.Levelwise Display
2.Mirror Image
3.Display height of a tree
4.Exit
1
BFS Traversal is:
50-40-60-30-45-55-70-end

Enter your choice:
1.Levelwise Display
2.Mirror Image
3.Display height of a tree
4.Exit
2
Mirror Image is:
50-60-40-70-55-45-30-end

Enter your choice:
1.Levelwise Display
2.Mirror Image
3.Display height of a tree
4.Exit
4
nidhi@nidhi-Inspiron-5523:~/Desktop$*/
