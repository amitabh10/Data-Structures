/*NIDHI SAINI,SY-E 38
ASSIGNMENT:Write a RemoveDuplicates() function which takes a list sorted in increasing order and deletes any duplicate nodes from the list.Ideally,the list should only be traversed once.*/
#include<stdio.h>
#include<stdlib.h>
struct abc
{
	int num;
	struct abc *next; 
};
typedef struct abc Node;
int ctr=0;
void display(Node *p)
{
	printf("\n");
	while(p!=NULL)
	{
		printf("%d ->  ",p->num);
		p=p->next;
	}
	printf("null\n");
}
Node *accept(int data)
{
	Node *temp;
	temp=malloc(sizeof(Node));
	if(temp==NULL)
	{
		printf("\nMemory Shortage!");
	}
	else
	{
		temp->num=data;
		temp->next=NULL;
		return temp;
	}
}
void RemoveDuplicates(Node *p)
{
	Node *q;
	do
	{
		q=p->next;
		if(p->num == q->num)
		{
			p->next=q->next;
			q->next=NULL;
			free(q);
			q=p->next;
		}
		else
		{
			p=p->next;
			q=q->next;
		}
	}while(q!=NULL);
}
void main()
{
	Node *head,*p,*new;
	int data,ch;
	head=NULL;
	do
	{
		printf("Enter element %d of the SLL:",ctr+1);
		scanf("%d",&data);
		new=accept(data);
		if(head==NULL)
			head=new;
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new;	
		}
		ctr++;
		printf("\nDo you want to enter more?(0/1):");
		scanf("%d",&ch);
	}while(ch!=0);
	printf("\nElements before removing duplicates:\n");
	display(head);	
	printf("\nElements after removing duplicates:\n");
	RemoveDuplicates(head);
	display(head);
}
/*OUTPUT:
nidhi@nidhi-Inspiron-5523:~$ cd Desktop/sem4/DSLab
nidhi@nidhi-Inspiron-5523:~/Desktop/sem4/DSLab$ gcc rdup_sll.c
nidhi@nidhi-Inspiron-5523:~/Desktop/sem4/DSLab$ ./a.out
Enter element 1 of the SLL:10

Do you want to enter more?(0/1):1
Enter element 2 of the SLL:20

Do you want to enter more?(0/1):1
Enter element 3 of the SLL:30

Do you want to enter more?(0/1):1
Enter element 4 of the SLL:30

Do you want to enter more?(0/1):1
Enter element 5 of the SLL:40

Do you want to enter more?(0/1):1
Enter element 6 of the SLL:50

Do you want to enter more?(0/1):1
Enter element 7 of the SLL:50

Do you want to enter more?(0/1):1
Enter element 8 of the SLL:70

Do you want to enter more?(0/1):0

Elements before removing duplicates:

10 ->  20 ->  30 ->  30 ->  40 ->  50 ->  50 ->  70 ->  null

Elements after removing duplicates:

10 ->  20 ->  30 ->  40 ->  50 ->  70 ->  null
nidhi@nidhi-Inspiron-5523:~/Desktop/sem4/DSLab$ */
