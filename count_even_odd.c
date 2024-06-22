#include<stdio.h>
int main(){
    int a[10];
    int evencount = 0;
    int oddcount = 0;
    printf("enter 10 no : ");
    for(int i=0;i<10;i++) {
         scanf("%d",&a[i]);
    }
     for(int i=0;i<10;i++) {
         if(a[i]%2==0) {
            evencount++;
         } else {
            oddcount++;
         }
    }
    printf("total even no is %d\n",evencount);
    printf("total odd no is %d",oddcount);
    
    return 0;
}