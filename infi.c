#include<stdio.h>
#define max 20
char stack[20];
int estack[20];
int tops=-1,tope=-1;
void push(char x[],char a,int *top)
{
	(*top)++;
	if(*top>=max)
		printf("\nStack Overflow");
	else
	{
		printf("\nPushed %c",a);
		x[(*top)]=a;
	}
}
char pop(char x[],int *top)
{
	char c;
	if(*top!=-1)
	{
		c=x[*top];
		(*top)--;
		printf("\nPopped %c",c);
		return c;
	}
	else
	{
		printf("\nStack Empty");
	}
}
void ipush(int x[],int a,int *top)
{
	(*top)++;
	if(*top>=max)
		printf("\nStack Overflow");
	else
	{
		printf("\nPushed %d",a);
		x[(*top)]=a;
	}
}
int ipop(int x[],int *top)
{
	int c;
	if(*top!=-1)
	{
		c=x[*top];
		(*top)--;
		printf("\nPopped %d",c);
		return c;
	}
	else
	{
		printf("\nStack Empty");
	}
}

char stacktop(char x[],int *top)
{
	char c;
	if((*top)!=-1)
	{
		c=pop(x,top);
		push(x,c,top);
		return c;
	}
}

char* getpost(char infix[])
{
	int i=0,ctr=0,j;
	char c,d,e,post[20]={0};
	while(infix[i]!='\0')
	{
		c=infix[i];
		switch(c)
		{
			case '(':
				push(stack,c,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/	
				break;
			case '{':
				push(stack,c,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/	
				break;
			case '[':
				push(stack,c,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/	
				break;
				
			case '+':
				d=stacktop(stack,&tops);
				while(d=='*' || d=='/' )
				{
					e=pop(stack,&tops);
					post[ctr]=e;
					ctr++;
					d=stacktop(stack,&tops);
				}
				push(stack,c,&tops);
				/*printf("\n%d",tops);
				for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/	
				break;
			case '-':
				d=stacktop(stack,&tops);
				while(d=='*' || d=='/')
				{
					e=pop(stack,&tops);
					post[ctr]=e;
					ctr++;
					d=stacktop(stack,&tops);
				}
				push(stack,c,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/
				break;
			case '*':
				d=stacktop(stack,&tops);
				push(stack,c,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/
				break;
			case '/':
				d=stacktop(stack,&tops);
				push(stack,c,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/
				break;
			case ')':
				d=stacktop(stack,&tops);
				while(d!='(')
				{
					e=pop(stack,&tops);
					post[ctr]=e;
					ctr++;
					d=stacktop(stack,&tops);
				}
				e=pop(stack,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/
				break;
			case '}':
				d=stacktop(stack,&tops);
				while(d!='{')
				{
					e=pop(stack,&tops);
					post[ctr]=e;
					ctr++;
					d=stacktop(stack,&tops);
				}
				e=pop(stack,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",j,stack[j]);
				*/
				break;
			case ']':
				d=stacktop(stack,&tops);
				while(d!='[')
				{
					e=pop(stack,&tops);
					post[ctr]=e;
					ctr++;
					d=stacktop(stack,&tops);
				}
				e=pop(stack,&tops);
				/*for(j=0;j<=tops;j++)
					printf("\n%d:%c",i,stack[j]);
				*/
				break;
			default:
				post[ctr]=c;
				ctr++;
				break;
		}
		//printf("\nCurrent Postfix Expression is:%s\n",post);
		i++;
	}
	/*for(i=0;i<=tops;i++)
		printf("\n%c",stack[i]);*/
	while(tops!=-1)
	{
		c=pop(stack,&tops);
		post[ctr]=c;
		ctr++;
	}
	post[ctr]='\0';
	strrev(post);
	return post;
}
int calc(int o1,char op,int o2)
{
	switch(op)
	{
		case '+':
			return o1+o2;
			break;
		case '-':
			return o1-o2;
			break;
		case '*':
			return o1*o2;
			break;
		case '/':
			return o1/o2;
			break;
		default:
			printf("\nError");
			break;
	}	
}
int evaluate(char post[])
{
	int i=0,t,t1;
	char c;
	while(post[i]!='\0')
	{
		c=post[i];
		if(isalpha(c))
		{
			printf("\nEnter Value for %c:",c);
			scanf("%d",&t);
			ipush(estack,t,&tope);
		}
		else
		{
			t=ipop(estack,&tope);
			t1=ipop(estack,&tope);
			t=calc(t,c,t1);
			ipush(estack,t,&tope);
		}
		i++;
	}
	return estack[0];	
}
void main()
{
	int y;
	char *post,infix[20];
	printf("Enter Infix Expression\n");
	scanf("%s",infix);
	strrev(infix);
	post=getpost(infix);
	printf("\nPostfix Expression is:%s\n",post);
	//y=evaluate(post);
	//printf("\nAnswer:%d",y);
}
