// Q1:- delete an Element from an Array.
#include <stdio.h>
int main() {
int arr[100], n, position, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position to delete: ");
            scanf("%d", &position);

            for (i = position; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;

            printf("Array after deletion:\n");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            return 0;

        }
