#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int coeff;
	int pow;
	struct link * next;
} poly;
int l1=0;
int l2=0;
void display(poly * p,int *n)
{
	int ctr=0;
	printf("\nThe polynomial expression is:\n");
	while(ctr<(*n))
    	{
		printf("%dx^%d", p->coeff, p->pow);
        	if(p->pow == 0)
                break;
		p = p->next;
		if(ctr!=(*n)-1)
			printf(" + ");
		ctr++;
    	}

}

poly* create(poly *head,int *n)
{
	int flag;
	int coeff, pow;
	poly *new,*p;
	head=NULL;
	do {
		new=malloc(sizeof(poly));
		printf("\nEnter Coeff:");
		scanf("%d", &coeff);
		new->coeff = coeff;
		printf("\nEnter Pow:");
		scanf("%d", &pow);
		new->pow = pow;
		new->next = NULL;
		if(head==NULL)
			head=new;
		else
		{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=new;
		}
		(*n)++;
		//printf("%d",(*n));
		display(head,n);
        	printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
		scanf("%d", &flag);
	} while(flag);
	new->next=head;
	return head;
}
void add(poly * p1, poly * p2,int *n1,int *n2)
{
	poly *new,*p;
	poly *head=NULL ;
	int i=0,j=0,k=0;
	while(i<(*n1) && j<(*n2))
        {
		new = malloc(sizeof(poly));
		new->next = NULL;
            	if (p1->pow > p2->pow)
            	{
               		new->pow = p1->pow;
                	new->coeff = p1->coeff;
                	p1 = p1->next;
			i++;
            	}	
            	else if (p1->pow < p2->pow)
            	{
                	new->pow = p2->pow;
                	new->coeff = p2->coeff;
                	p2 = p2->next;
			j++;
            	}
            	else
            	{
                	new->pow = p1->pow;
                	new->coeff = p1->coeff + p2->coeff;
                	p1 = p1->next;
                	p2 = p2->next;
			i++;
			j++;
            	}
            	if(head==NULL)
			head=new;
		else
		{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=new;
		}
		k++;
        }
        while(i<(*n1))
        {
		new = malloc(sizeof(poly));
	  	new->next = NULL;
		new->pow = p1->pow;
		new->coeff = p1->coeff;
		p1 = p1->next;
		if(head==NULL)
			head=new;
		else
		{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=new;
		}
		i++;
		k++;
        }
        while(j<(*n2))
        {
		new = malloc(sizeof(poly));
	  	new->next = NULL;
		new->pow = p2->pow;
		new->coeff = p2->coeff;
		p2 = p2->next;
		if(head==NULL)
			head=new;
		else
		{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=new;
		}
		j++;
		k++;
        }
	new->next=head;
        printf("\nAddition Complete");
	display(head,&k);

}

void mul(poly * p1, poly * p2,int *n1,int *n2)
{
	int i=0,j=0,k=0;
    	poly *new,*p,*q,*result;
	result=NULL;
	while(j<(*n2))
    	{
        	while(i<(*n1))
        	{
			new = malloc(sizeof(poly));
			new->next = NULL;
		
	                new->pow = p1->pow + p2->pow;
	                new->coeff = (p1->coeff)*(p2->coeff);
	                p1 = p1->next;
			if(result==NULL)
				result=new;
			else
			{	
				p=result;
				while(p->next!=NULL)
					p=p->next;
				p->next=new;
			}
			i++;
			k++;	                
	        }
		i=0;
	        p2 = p2->next;
	        j++;
	}
	p=result;
	do
	{
		q=p->next;
		if(p->pow == q->pow)
		{
			p->coeff=p->coeff+q->coeff;
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
	new->next=result;
	printf("\nMultiplication Done\n");
	display(result,&k);
}
void main()
{

	int flag=0,c;
	poly *p1,*p2;
    	do {
		printf("\n1.Input\n2.Add\n3.Multiply\n4.Exit\nEnter:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				p1=NULL;
				p2=NULL;
				l1=0;
				l2=0;
				printf("\nCreate 1st expression\n");
				p1=create(p1,&l1);
				printf("\nStored the 1st expression\n");
				display(p1,&l1);
				printf("\nCreate 2nd expression\n");
				p2=create(p2,&l2);
				printf("\nStored the 2nd expression\n");
				display(p2,&l2);
				flag=1;
				break;
        		case 2:
				if(flag==1)
					add(p1, p2,&l1,&l2);
				else
					printf("\nInput first!\n");
				break;
		
			case 3:
        			if(flag==1)
					mul(p1, p2,&l1,&l2);
				else
					printf("\nInput first!\n");
				break;
			case 4:
				printf("\nThankyou!\n");
				break;
			default:
				printf("\nWrong Input!\n");
				break;
		}
	    }while (c!=4);
}

