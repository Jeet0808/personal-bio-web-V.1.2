#include<stdio.h>
#include<string.h>
int main(){
    int l1,l2;
    char s1[40] = "jeet ";
    char s2[40] = "solanki";
    l1 = strlen(s1);
    l2 = strlen(s2);
    for(int i=0;i<=l2;i++) {
        s1[l1+i]= s2[i];

    }
    printf("string after concatinating is %s",s1);
    return 0;
}