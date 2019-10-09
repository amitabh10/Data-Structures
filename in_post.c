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
