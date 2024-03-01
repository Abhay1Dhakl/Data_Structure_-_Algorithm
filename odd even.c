#include<stdio.h>
void main()
{
    int a,b,c;
    printf("enter your three number");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b & a > c){
        printf("greater number is %d",a);
    }
    else if(b>a & b>c){
        printf("greater number is %d",b);
    }
    else{
        printf("greater number is %d",c);
    }
}
