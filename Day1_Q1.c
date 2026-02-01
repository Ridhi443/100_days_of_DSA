// Q1:- insert an Element in an Array.
#include <stdio.h>
int main() {
    int arr[100], n, position, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter position and value to insert: ");
    scanf("%d %d", &position, &value);

    for (i = n; i > position; i--)
        arr[i] = arr[i - 1];

    arr[position] = value;
    n++;

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}