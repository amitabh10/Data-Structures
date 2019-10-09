/*NIDHI SAINI,SY-E 38
ASSIGNMENT:WAP to convert a given Infix expression into its equivalent Postfix expression and evaluate it using stack.*/
#include<stdio.h>
#include<stdlib.h>
#define max 30
char stk[max];
int top=-1,topn=-1,num[max];
int numpop()
{
	int no;
	if(topn==-1)
	{
		printf("Stack Empty!");
		exit(0);
	}
	else
	{
		no=num[topn];
		printf("Popping %d\n",no);
		topn--;
		return no;
	}
}
void numpush(int no)
{
	if(topn==(max-1))
	{
		printf("Stack Full!");
		exit(0);
	}
	else
	{
		topn++;
		printf("Pushing %d\n",no);
		num[topn]=no;
	}
}
int calc(int n1,char op,int n2)
{
	switch(op)
	{
		case '+':
			return n1+n2;
			break;
		case '-':
			return n1-n2;
			break;
		case '*':
			return n1*n2;
			break;
		case '/':
			return n1/n2;
			break;
		default:
			printf("\nError");
			break;
	}	
}
void evaluate(char post[])
{
	int i=0,t1,t2;
	char a;
	while(post[i]!='\0')
	{
		a=post[i];
		if(isalpha(a))
		{
			printf("Enter value for %c:",a);
			scanf("%d",&t1);
			numpush(t1);
		}
		else
		{
			t2=numpop();
			t1=numpop();
			t1=calc(t1,a,t2);
			numpush(t1);
		}
		i++;
	}
	printf("Answer:%d\n",num[0]);
}
void push(char op)
{
	if(top==(max-1))
	{
		printf("Stack Full!");
		exit(0);
	}
	else
	{
		top++;
		printf("Pushing %c\n",op);
		stk[top]=op;
	}
}
char pop()
{
	char op;
	if(top==-1)
	{
		printf("Stack Empty!");
		exit(0);
	}
	else
	{
		op=stk[top];
		printf("Popping %c\n",op);
		top--;
		return op;
	}
}
char stacktop()
{
	char op;
	if(top!=-1)
	{
		op=pop();
		push(op);
		return op;
	}
}
void getpost(char in[])
{
	int i=0,ctr=0;
	char stktop,post[30]={'\0'},c;
	while(in[i]!='\0')
	{
		c=in[i];
		switch(c)
		{
			case '(':
				push(c);
				break;
			case '[':
				push(c);
				break;
			case '{':
				push(c);
				break;
			case ')':
				stktop=stacktop();
				while(stktop!='(')
				{
					post[ctr]=pop();
					ctr++;
					stktop=stacktop();
				}
				pop();
				break;
			case ']':
				stktop=stacktop();
				while(stktop!='[')
				{
					post[ctr]=pop();
					ctr++;
					stktop=stacktop();
				}
				pop();
				break;
			case '}':
				stktop=stacktop();
				while(stktop!='{')
				{
					post[ctr]=pop();
					ctr++;
					stktop=stacktop();
				}
				pop();
				break;
			case '+':
				stktop=stacktop();
				while(stktop=='/' || stktop=='*' || stktop=='-' || stktop=='+')
				{
					post[ctr]=pop();
					ctr++;
					stktop=stacktop();
				}
				push(c);
				break;
			case '-':
				stktop=stacktop();
				while(stktop=='/' || stktop=='*' || stktop=='-' || stktop=='+')
				{
					post[ctr]=pop();
					ctr++;
					stktop=stacktop();
				}
				push(c);
				break;
			case '/':
				stktop=stacktop();
				while(stktop=='/' || stktop=='*')
				{
					post[ctr]=pop();
					ctr++;
					stktop=stacktop();
				}
				push(c);
				break;
			case '*':
				stktop=stacktop();
				while(stktop=='/' || stktop=='*')
				{
					post[ctr]=pop();
					ctr++;
					stktop=stacktop();
				}
				push(c);
				break;
			default:
				post[ctr]=c;
				ctr++;
				break;
		}
		printf("\nPostfix:%s\n",post);
		i++;
	}
	while(top!=-1)
	{
		post[ctr]=pop();
		ctr++;
		printf("\nPostfix:%s\n",post);
	}
	post[ctr]='\0';
	printf("\nPostfix:%s\n",post);
	evaluate(post);
}
void main()
{
	char in[30];
	printf("Enter the infix expression:");
	scanf("%s",in);
	getpost(in);
	
}
/*OUTPUT:
vit@lab1309-16:~$ cd Desktop
vit@lab1309-16:~/Desktop$ gcc in_post.c
vit@lab1309-16:~/Desktop$ ./a.out
Enter the infix expression:a+b*c/d

Postfix:a
Pushing +

Postfix:a

Postfix:ab
Popping +
Pushing +
Pushing *

Postfix:ab

Postfix:abc
Popping *
Pushing *
Popping *
Popping +
Pushing +
Pushing /

Postfix:abc*

Postfix:abc*d
Popping /

Postfix:abc*d/
Popping +

Postfix:abc*d/+

Postfix:abc*d/+
Enter value for a:1
Pushing 1
Enter value for b:1
Pushing 1
Enter value for c:1
Pushing 1
Popping 1
Popping 1
Pushing 1
Enter value for d:1
Pushing 1
Popping 1
Popping 1
Pushing 1
Popping 1
Popping 1
Pushing 2
Answer:2
vit@lab1309-16:~/Desktop$ gcc in_post.c
vit@lab1309-16:~/Desktop$ ./a.out
Enter the infix expression:(a+b)*c-(d*e)
Pushing (

Postfix:

Postfix:a
Popping (
Pushing (
Pushing +

Postfix:a

Postfix:ab
Popping +
Pushing +
Popping +
Popping (
Pushing (
Popping (

Postfix:ab+
Pushing *

Postfix:ab+

Postfix:ab+c
Popping *
Pushing *
Popping *
Pushing -

Postfix:ab+c*
Pushing (

Postfix:ab+c*

Postfix:ab+c*d
Popping (
Pushing (
Pushing *

Postfix:ab+c*d

Postfix:ab+c*de
Popping *
Pushing *
Popping *
Popping (
Pushing (
Popping (

Postfix:ab+c*de*
Popping -

Postfix:ab+c*de*-

Postfix:ab+c*de*-
Enter value for a:1
Pushing 1
Enter value for b:1
Pushing 1
Popping 1
Popping 1
Pushing 2
Enter value for c:1
Pushing 1
Popping 1
Popping 2
Pushing 2
Enter value for d:1
Pushing 1
Enter value for e:1
Pushing 1
Popping 1
Popping 1
Pushing 1
Popping 1
Popping 2
Pushing 1
Answer:1
vit@lab1309-16:~/Desktop$*/ 

