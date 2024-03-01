#include<stdio.h>
int gcd(int ,int );
void main()
{
    int a,b;
    printf("enter your numbers");
    scanf("%d %d",&a,&b);
    printf("your gcd of %d and %d is %d",a,b,gcd(a,b));
}
int gcd(int x,int y)
{
    if(y=0)
    {
        return gcd(y,x%y);
    }
    else
        return x;

}
