/*Problem: Write a program to perform addition of two matrices having the same dimensions. 
The sum of two matrices is obtained by adding corresponding elements of the matrices.*/
#include <stdio.h>
 int main() {
    int m,n;
    int i,j;
    scanf("%d %d", &m,&n);
int A[m][n],B[m][n],sum[m][n];
for(i=0;i<m;i++) {
    for (j=0;j<n;j++) {
        scanf("%d",&A[i][j]);
    }
}
for(i=0;i<m;i++) {
    for (j=0;j<n;j++) {
        scanf("%d",&B[i][j]);
    }
}
for(i=0;i<m;i++) {
    for (j=0;j<n;j++) {
        sum[i][j]=A[i][j] + B[i][j];
    }
}
for(i=0;i<m;i++) {
    for (j=0;j<n;j++) {
        printf("%d ",sum[i][j]);
    }
    printf("\n");
}
return 0;
}