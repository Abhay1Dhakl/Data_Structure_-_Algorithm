#include<stdio.h>

void main()
{
    int flag=0,i,n,key,a[20];
    printf("enter the number of array cells");
    scanf("%d",&n);
    printf("\nenter the elements of array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nenter the number you want to search");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key){
            flag == 1;}
       printf("\n%d",a[i]);
    }
    if(flag == 1)
        printf("Search Successful");
    else
        printf("Search Unsuccessful");
}
