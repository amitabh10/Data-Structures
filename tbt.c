//Nidhi Saini,SY-E-38
#include<stdio.h>
#include<stdlib.h>
struct n
{
    int lth;
    int rth;
    int data;
    struct n *left,*right;
};
typedef struct n node;
int i=0,j,a[20];
node* getnode(int data)
{
    node *temp;
    temp=malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("\nMemory Shortage\n");
        exit(0);
    }
    else
    {
        temp->lth=1;
        temp->rth=1;
        temp->left=temp;
        temp->right=temp;
        temp->data=data;
        return temp;
    }
}
void in(node *head)
{
	node *root,*p;
	root=head->left;
	p=root;
	printf("\n");
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
	printf("null");
}
void pre(node *head)
{
	node *root,*p;
	root=head->left;
	p=root;
	printf("\n");
	do
	{
		while(p->lth!=1)
		{
			printf("%d->",p->data);
			p=p->left;
		}
		printf("%d->",p->data);
		while(p->rth==1 && p->right!=head)
		{
			p=p->right;
		}
		p=p->right;
	}while(p!=head);
	printf("null");
}
void post(node *head)
{
	int postarr[20],i,ctr=0;
	node *root,*p;
	root=head->left;
	p=root;
	printf("\n");
	do
	{
		while(p->rth!=1)
		{
			postarr[ctr]=p->data;
			ctr++;
			p=p->right;
		}
		postarr[ctr]=p->data;
		ctr++;
		while(p->lth==1 && p->left!=head)
		{
			p=p->left;
		}
		p=p->left;
	}while(p!=head);
	for(i=ctr-1;i>=0;i--)
	{
		printf("%d->",postarr[i]);
	}
	printf("null");
}
node* create(node *head)
{
    node *root,*p,*q,*n;
    root=NULL;
    int t,ch,flag;
    do
    {
        printf("\nEnter data:");
        scanf("%d",&t);
        n=getnode(t);
        if(root==NULL)
        {
            root=n;
            head->left=root;
            head->lth=0;
            root->left=head;
            root->right=head;
        }
        else
        {
            p=root;
            do
            {
                flag=0;
                if(p->data>n->data)
                {
                    if(p->lth==1)
                    {
                        //printf("p->data=%d",p->data);
                        n->left=p->left;
                        n->right=p;
                        p->left=n;
                        p->lth=0;
                        flag=1;
                    }
                    else
                        p=p->left;
                }
                else
                {
                    if(p->rth==1)
                    {
                        n->right=p->right;
                        n->left=p;
                        p->right=n;
                        p->rth=0;
                        flag=1;
                    }
                    else
                        p=p->right;
                }
            }while(flag!=1);
        }
        in(head);
        printf("\nDo you want more nodes?(1/0)\n");
        scanf("%d",&ch);
    }while(ch!=0);
    return head;
}
void main()
{
    node *header;
    int ch,flag=0;
    do{
        printf("\n-----THREADED BINARY TREES-----\n1.Input\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Exit\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
		{
			case 1:
				header=getnode(32767);
    				header=create(header);
				flag=1;
				break;
			case 2:
				if(flag==1)
					in(header);
				else
					printf("\nPlease Input!\n");
				break;
			case 3:
				if(flag==1)
					pre(header);
				else
					printf("\nPlease Input!\n");
				break;
			case 4:
				if(flag==1)
					post(header);
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
/*	OUTPUT
amitabh@amitabh-Inspiron-7537:~$ cd Desktop
amitabh@amitabh-Inspiron-7537:~/Desktop$ gcc tbt1.c
amitabh@amitabh-Inspiron-7537:~/Desktop$ ./a.out

-----THREADED BINARY TREES-----
1.Input
2.Inorder Traversal
3.Preorder Traversal
4.Postorder Traversal
5.Exit
Enter Your Choice:1

Enter data:30

30->null
Do you want more nodes?(1/0)
1

Enter data:20

20->30->null
Do you want more nodes?(1/0)
1

Enter data:10

10->20->30->null
Do you want more nodes?(1/0)
1

Enter data:25

10->20->25->30->null
Do you want more nodes?(1/0)
1

Enter data:40

10->20->25->30->40->null
Do you want more nodes?(1/0)
1

Enter data:50

10->20->25->30->40->50->null
Do you want more nodes?(1/0)
0

-----THREADED BINARY TREES-----
1.Input
2.Inorder Traversal
3.Preorder Traversal
4.Postorder Traversal
5.Exit
Enter Your Choice:2

10->20->25->30->40->50->null
-----THREADED BINARY TREES-----
1.Input
2.Inorder Traversal
3.Preorder Traversal
4.Postorder Traversal
5.Exit
Enter Your Choice:3

30->20->10->25->40->50->null
-----THREADED BINARY TREES-----
1.Input
2.Inorder Traversal
3.Preorder Traversal
4.Postorder Traversal
5.Exit
Enter Your Choice:4

10->25->20->50->40->30->null
-----THREADED BINARY TREES-----
1.Input
2.Inorder Traversal
3.Preorder Traversal
4.Postorder Traversal
5.Exit
Enter Your Choice:5

Thankyou!
*/
