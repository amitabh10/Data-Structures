#include<stdio.h>
#include<string.h>
#define max 20
char stack[20];
int top;
void push(char c)
{
    top++;
    if(top>=max)
        printf("Stack Overflow!\n");
    else
    {
        printf("\nPushed %c",c);
        stack[top]=c;
    }
}
int stackempty()
{
    return top;
}
char pop()
{
    char c;
    if(stackempty()!=-1)
    {
        c=stack[top];
        printf("\nPopped %c",c);
        top--;
        return c;
    }
    else
        printf("\nStack Empty\n");
}
char stacktop(char x[],int l)
{
    char c;
    c=pop();
    push(c);
    return c;
}
void assign(char x[])
{
    int i=0;
    while(x[i]!='\0')
    {
		printf("\nPushing %c",x[i]);
        push(x[i]);
        i++;
    }
    x[i]='\0';
}
void rev()
{
	int i;
    char x,a[20];
    printf("Enter String\n");
    scanf("%s",a);
    assign(a);
	i=0;
    while(top!=-1)
    {
		x=pop();
        a[i]=x;
		i++;
    }
    a[i]='\0';
	printf("\nReversed String:%s",a);
}

int palin()
{
	int i;
    char a[20],b[20],x;
    printf("Enter String\n");
    scanf("%s",a);
    assign(a);
	i=0;
    while(top!=-1)
    {
		x=pop();
        b[i]=x;
		i++;
    }
    b[i]='\0';
	while(a[i]!='\0' && b[i]!='\0')
	{
		if(a[i]!=b[i])
			return -1;
	}	
	return 1;
}
char* concat()
{
    int i=0,ctr=0;
    char x,a[20],b[20];
    printf("\nEnter String 1:");
    scanf("%s",a);
    printf("\nEnter String 2:");
    scanf("%s",b);
    assign(a);
    while(b[i]!='\0')
    {
        push(b[i]);
		i++;
    }
	stack[top+1]='\0';
    return stack;
}
int comp()
{
	int i;
	char x,a[20],b[20];
    printf("\nEnter String 1:");
    scanf("%s",a);
    printf("\nEnter String 2:");
    scanf("%s",b);
	strupr(a);
	strupr(b);
	strrev(a);
    assign(a);
	i=0;
	while(top!=-1 && b[i]!='\0')
	{
		x=pop();
		if(x!=b[i])
		{
			if(x>b[i])
				return 1;
			else
				return 2;
		}
		i++;
	}
	if(top!=-1)
	{
		return 1;
	}
	else if(b[i]!='\0')
	{
		return 2;
	}
	return 0;    
}
void main()
{
    int i=0,ch,p;
    char *ans;
    do
    {
        printf("String Operations\n1.Palindrome\n2.Reverse String\n3.Concatenate Strings\n4.Compare String\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    top=-1;
                    p=palin();
                    if(p==1)
                        printf("\nIt is a Palindrome!\n");
                    else
                        printf("\nIt is not a Palindrome!\n");
                    break;
            case 2:
                    top=-1;
                    rev();
                    break;
            case 3:
                    top=-1;
                    ans=concat();
                    printf("\nConcatenated String:%s\n",ans);
                    break;
            case 4:
                    top=-1;
                   	p=comp();
                    if(p==0)
                        printf("\nBoth Strings are same!\n");
                    else if(p==1)
                        printf("\nString 1 is Greater!\n");
					else
						printf("\nString 2 is Greater!\n");
                    break;
            case 5:
                    printf("ThankYou!\n");
                    break;
            default:
                    printf("Wrong Choice!\n");
                    break;
        }
    }while(ch!=5);
}
