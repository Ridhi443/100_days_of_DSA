// Problem: For each element, count how many smaller elements appear on right side. Use merge sort technique or Fenwick Tree (BIT).
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
    int count;
} Element;

void merge(Element arr[], int left, int mid, int right, int result[]) {
    int i = left, j = mid + 1, k = left;
    Element temp[right - left + 1];
    
    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value) {
            temp[k - left] = arr[i];
            temp[k - left].count += (j - mid - 1);
            i++;
        } else {
            temp[k - left] = arr[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        temp[k - left] = arr[i];
        temp[k - left].count += (j - mid - 1);
        i++;
        k++;
    }
    
    while (j <= right) {
        temp[k - left] = arr[j];
        j++;
        k++;
    }
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(Element arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right, NULL);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    Element arr[n];
    int result[n];
    
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        arr[i].count = 0;
    }
    
    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        result[arr[i].index] = arr[i].count;
    }
    
    printf("Count of smaller elements on right: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}