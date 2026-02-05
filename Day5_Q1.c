#include <stdio.h>

int main() {
    int p, q;
    int i = 0, j = 0, k = 0;

    int log1[100], log2[100], merged[200];

    // Read size and elements of first log
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Read size and elements of second log
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    i = 0;
    j = 0;

    // Merge the two sorted arrays
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements
    while (i < p) {
        merged[k++] = log1[i++];
    }

    while (j < q) {
        merged[k++] = log2[j++];
    }

    // Print merged array
    for (i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
