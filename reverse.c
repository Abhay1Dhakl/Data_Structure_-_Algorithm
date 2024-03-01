#include<stdio.h>
int reverse(int);
void main()
{
    int a,re;
    printf("enter your number to be reversed");
    scanf("%d",&a);
    printf("reversed number is %d",reverse(a));
}
reverse(int a)
{
    int rev=0,rem;

    if(a)
    {
        rem=a%10;
        rev=rev*10+rem;
        a=a/10;
    }
    else
        return rev;
    return rev;
}
