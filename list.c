#include<stdio.h>
int  insertion(int a[],int n);
void main(){
int a[10],i,n;
printf("enter your number of elements");
scanf("%d",&n);
printf("enter elements");
for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
}
insertion(a,n);
}
int insertion(int a[],int n){
    int i,pos,el,temp;
    printf("enter your position");
    scanf("%d",&pos);
    if(pos>=n+1){
        printf("enter position less then or equals to %d",n);
    }
    else if( pos == n){
        printf("enter your element");
        scanf("%d",&a[pos]);
        for(i = 0 ; i <= pos ; i++){
    printf("%d",a[i]);
}
    }
    else{
        temp = n - 1;
        while(temp >= pos){
            a[temp + 1] = a [temp];
            temp --;
        }
        printf("enter your element to be added");
        scanf("%d",&el);
        a[pos] = el;
        for(i = 0 ; i <=n ; i++){
    printf("%d",a[i]);
}
    }

}
