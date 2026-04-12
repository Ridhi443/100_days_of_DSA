/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, 
traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.*/
#include <stdio.h>
int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    int matrix[row][col];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = row - 1, left = 0, right = col - 1;

    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}