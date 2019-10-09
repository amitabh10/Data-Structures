#include<stdio.h>
#define max 20
char a[20],b[20],c[20],d[20];
int top[]={-1,-1,-1,-1};
void push(char x[],char c,int l)
{
    top[l]++;
    if(top[l]>=max)
        printf("Stack Overflow!\n");
    else
    {
        printf("\nPushed %c",c);
        x[top[l]]=c;
    }
}
int stackempty(int l)
{
    return top[l];
}
char pop(char x[],int l)
{
    char c;
    if(stackempty(l)!=-1)
    {
        c=x[top[l]];
        printf("\nPopped %c",c);
        top[l]--;
        return c;
    }
    else
        printf("\nStack Empty\n");
}
char stacktop(char x[],int l)
{
    char c;
    c=pop(x,l);
    push(x,c,l);
    return c;
}
void assign(char x[],int l)
{
    int i=0;
    while(x[i]!='\0')
    {
		printf("\nPushing %c",x[i]);
        push(x,x[i],l);
        i++;
    }
    x[i]='\0';
}
void rev()
{
	int i;
    char x;
    printf("Enter String\n");
    scanf("%s",a);
    assign(a,0);
	i=0;
    while(a[i]!='\0')
    {
		x=pop(a,0);
        push(b,x,1);
		i++;
    }
    b[i]='\0';
}
int palin()
{
    int i=0;
    char x,y;
    rev();
    assign(a,0);
    i=0;
    while(a[i]!='\0' && b[i]!='\0')
    {
            x=pop(a,0);
            y=pop(b,1);
            if(x!=y)
            return -1;
            i++;
    }
    return 1;
}
char* concat()
{
    int i=0,ctr=0;
    char x;
    printf("\nEnter String 1:");
    scanf("%s",a);
    printf("\nEnter String 2:");
    scanf("%s",b);
    assign(a,0);
    assign(b,1);
    while(b[i]!='\0')
    {
        x=pop(b,1);
        push(c,x,2);
        i++;
    }
    ctr=ctr+i;
    i=0;
    while(a[i]!='\0')
    {
        x=pop(a,0);
        push(c,x,2);
        i++;
    }
    ctr=ctr+i;
    c[ctr]='\0';
    i=0;
    while(c[i]!='\0')
    {
        x=pop(c,2);
        push(d,x,3);
        i++;
    }
    d[i]='\0';
    return d;
}
int comp()
{
    int i=0,ctr=0;
    char x,y;
    printf("\nEnter String 1:");
    scanf("%s",a);
    printf("\nEnter String 2:");
    scanf("%s",b);
    assign(a,0);
    assign(b,1);
    while(a[i]!='\0' && b[i]!='\0')
    {
        x=pop(a,0);
        y=pop(b,1);
        if(x!=y)
            return -1;
        i++;
    }
    if(stackempty(0)!=-1)
    {
        return -1;
    }
    else if(stackempty(1)!=-1)
    {
        return -1;
    }
    return 1;
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
                    top[0]=top[1]=top[2]=top[3]=-1;
                    p=palin();
                    if(p==1)
                        printf("\nIt is a Palindrome!\n");
                    else
                        printf("\nIt is not a Palindrome!\n");
                    break;
            case 2:
                    top[0]=top[1]=top[2]=top[3]=-1;
                    rev();
                    printf("\nReversed String:%s\n",b);
                    break;
            case 3:
                    top[0]=top[1]=top[2]=top[3]=-1;
                    ans=concat();
                    printf("\nConcatenated String:%s\n",ans);
                    break;
            case 4:
                    top[0]=top[1]=top[2]=top[3]=-1;
                    p=comp();
                    if(p==1)
                        printf("\nBoth Strings are same!\n");
                    else
                        printf("\nNot Same!\n");
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
