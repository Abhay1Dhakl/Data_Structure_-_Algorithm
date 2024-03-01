#include<stdio.h>
void main()
{
    int a[5],i,j,temp;
    printf("enter your elements");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("entered elements are");
    for(i=0;i<5;i++)
    {
    printf("\n%d",a[i]);
    }

    for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(a[j]>a[j+1])
                   {
                       temp = a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                   }
            }
        }
        printf("\nnsorted elements are:");
        for(i=0;i<5;i++)
        {
      printf("\n%d",a[i]);
        }
}
