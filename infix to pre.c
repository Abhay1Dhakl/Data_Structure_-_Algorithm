#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int presta(char);
void main()
{
    int i,length,ops=-1,pre=-1;
    char infix[100],opstack[50],prestack[50];
    printf("enter your infix character:");
    gets(infix);
    length=strlen(infix);
    strrev(infix);
    for(i=0;i<length;i++)
    {
        if(infix[i]==')')
        {
            opstack[++ops]=infix[i];
        }
        else if(isalpha(infix[i]))
        {
            prestack[++pre]=infix[i];
        }
        else if(infix[i]=='(')
        {
            while(opstack[ops]!=')')
            {
                prestack[++pre]=opstack[ops];
                --ops;
            }
            --ops;
        }
        else{
            if(presta(opstack[ops])>presta(infix[i]))
            {
                prestack[++pre]=opstack[ops];
                ops--;
            }
            opstack[++ops]=infix[i];
        }
    }
    while(ops!=-1)
    {
        prestack[++pre]=opstack[ops];
        --ops;
    }
   /* for(i=length;i>0;i--)
    {
        printf(" %c",prestack[i]);
    }*/

    puts(strrev(prestack));
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
