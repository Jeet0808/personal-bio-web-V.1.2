# include<stdio.h>
int main(){
    int a[3][4] = {{1,2,3,4},{1,1,1,1},{0,0,0,0}};
    printf("matrix is : \n ");
    for(int i=0;i<3;i++) {
       for(int j=0;j<4;j++) {
        printf("%d",a[i][j]);
       }
       printf("\n");
    }
    printf("Transpose of this matrix is :\n ");
    for(int i=0;i<4;i++) {
       for(int j=0;j<3;j++) {
        printf("%d",a[j][i]);
       }
       printf("\n");
    }
    return 0;

}