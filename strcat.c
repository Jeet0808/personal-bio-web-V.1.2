#include<stdio.h>
#include<string.h>

int main(){
    char s1[30] = "jeet ";
    char s2[30] = "solanki";
    strcat(s1,s2);
    printf("String after concatination = %s",s1);
    return 0;
}