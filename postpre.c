#include<stdio.h>
#include<string.h>
#define max 20
char stack[20][20]={0};
int top=-1;
void push(char *a)
{
	top++;
	if(top>=max)
	printf("Stack Full!\n");
	else
	{
		printf("\nPushing %s",a);
		strcpy(stack[top],a);
		printf("\nstack-top:%s",stack[top]);
	}
}
char* pop()
{
	char *a;
	if(top!=-1)
	{
		strcpy(a,stack[top]);
		printf("\nPopping %s",a);
		top--;
		return a;
	}
	else
	printf("Stack Empty!\n");
}
void join(char *op,char *o1,char *o2)
{
	strcat(op,o1);
	strcat(op,o2);
	push(op);
}
char* getpre(char post[])
{
	int i=0,j;
	char *x,y,*w,t3[10],t4[10];
	char z='\0';
	w=&z;
	char *t1,*t2;
	post[strlen(post)]='\0';
	while(post[i]!='\0')
	{
		y=post[i];	
		x=&y;
		strcat(x,w);
		strcpy(t4,x);
		printf("\n%s\n",x);
		if(isalpha(post[i]))
		{
			push(x);
		}
		else
		{
			printf("\n%s\n",x);
			t2=pop();
			strcpy(t3,t2);
			printf("\n%s\n",x);
			t1=pop();
			printf("\n%s\n",x);
			printf("\nx:%s\tt1:%s\tt2:%s",x,t1,t3);
			join(,t1,t3);
		}
		/*printf("\n---STACK---\n");
		for(j=0;j<=i;j++)
			printf("\n%d:%s",j,stack[j]);
		printf("\n-----------\n");*/
		i++;
	}
	return stack[0];
}
void main()
{
	char post[20],*pre;
	printf("Enter Postfix Expr\n");
	scanf("%s",post);
	pre=getpre(post);
	printf("\nPefix:%s\n",pre);
}
