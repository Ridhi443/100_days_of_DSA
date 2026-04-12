/*Problem: Given a matrix, calculate the sum of its primary diagonal elements.
 The primary diagonal consists of elements where row index equals column index.*/
 #include <stdio.h>
 int main() {
    int m,n;
    int i;

    scanf("%d %d",&m,&n);
    int matrix[m][n];
    int sum=0;
    for(i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
for (i=0;i<m && i<n;i++) {
    sum +=matrix[i][i];
}
printf("%d",sum);
return 0;
 }