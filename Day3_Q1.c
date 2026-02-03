#include <stdio.h>

int main() {
    int a[100], n, key, i;
    int comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        comparisons++;
        if(a[i] == key) {
            printf("Element found at position %d\n", i + 1);
            printf("Number of comparisons = %d\n", comparisons);
            return 0;
        }
    }

    printf("Element not found\n");
    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}
