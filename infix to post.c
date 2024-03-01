#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int presta(char);
void main()
{
    int i,length,ops=-1,pos=-1;
    char infix[100],opstack[50],poststack[50];
    printf("enter your infix character:");
    gets(infix);
    length=strlen(infix);
    for(i=0;i<length;i++)
    {
        if(infix[i]=='(')
        {
            opstack[++ops]=infix[i];
        }
        else if(isalpha(infix[i]))
        {
            poststack[++pos]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(opstack[ops]!='(')
            {
                poststack[++pos]=opstack[ops];
                --ops;
            }
            --ops;
        }
        else{
            if(presta(opstack[ops])>presta(infix[i]))
            {
                poststack[++pos]=opstack[ops];
                --ops;
            }
            opstack[++ops]=infix[i];
        }
    }
    while(ops!=-1)
    {
        poststack[++pos]=opstack[ops];
        --ops;
    }
    for(i=0;i<=length;i++)
    {
        printf(" %c",poststack[i]);
    }

}
int presta(char a)
{
    switch(a)
    {
        case '$':
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        default:
            return 0;
    }
}
