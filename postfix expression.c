#include<stdio.h>
#include<string.h>
#include<math.h>
int precedence(char);
void main()
{
    int pos=-1,ops=-1,TOP=-1,length,i=0,a,b,ans=0,value[100];
    char infix[100],poststack[100],opstack[100],variable[50];
    printf("enter your infix:");
    gets(infix);
    length=strlen(infix);
    for(i=0;i<length;i++)
{
     if(isalpha(infix[i]))
        {
        TOP++;
        printf("\nenter the value of %c character",infix[i]);
        scanf("%d",&value[TOP]);
        }
}
 for(i=0;i<length;i++)
        {

            if(isalpha(infix[i]))
                    {
                        poststack[++pos]=value[TOP];
                        TOP--;
                    }
            else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='$')
            {
                        a=poststack[pos];
                        poststack[pos]='\0';
                        pos--;
                        b=poststack[pos];
                        poststack[pos]='\0';
                        pos--;
                        switch(infix[i])
                        {
                        case '+':
                            ans=b+a;
                            break;
                        case '-' :
                            ans=b-a;
                            break;
                        case '*':
                            ans=b*a;
                            break;
                        case '/':
                            ans=b/a;
                            break;
                        case '$':
                            ans=pow(b,a);
                            break;
                        default:
                            ans=0;
                            break;
                        }
                        pos++;
                     poststack[pos]=ans;
            }
            /*else
            {
                if(precedence(opstack[ops])>=precedence(infix[i]))
                {
                    if(opstack[ops]=='+')
                        {
                            ans=a+b;
                            ops--;
                        }
                        else if(opstack[ops]=='-')
                        {
                            ans=a-b;
                            ops--;
                        }
                        else if(opstack[ops]=='*')
                        {
                            ans=a*b;
                            ops--;
                        }
                        else if(opstack[ops]=='/')
                        {
                            ans=a/b;
                            ops--;
                        }
                        else if(opstack[ops]=='$')
                        {
                            ans=pow(a,b);
                            ops--;
                        }
                         poststack[++pos]=ans;
                }
                else
                {
                    opstack[++ops]=infix[i];
                }
            }*/
}
printf("\n%d\n", poststack[pos]);
}
/*int precedence(char a)
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
}*/
