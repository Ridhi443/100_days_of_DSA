//Q:-remove duplicates from sorted array.
#include <stdio.h>
int main () {
    int i,n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
     for (i=0;i<n;i++) {
    scanf("%d",&arr[i]);
}
if(n>0) {
printf("%d ",arr[0]);
}
for(i=1;i<n;i++) {
    if(arr[i]!=arr[i-1]) {
        printf("%d ",arr[i]);
    }
}
return 0;
}