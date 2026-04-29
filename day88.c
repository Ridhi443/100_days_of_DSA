// Problem Statement: Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;
    int last = stalls[0];
    for(int i = 1; i < n; i++) {
        if(stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
            if(count == k) return 1;
        }
    }
    return 0;
}

int maxMinDistance(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), cmp);
    int low = 0;
    int high = stalls[n-1] - stalls[0];
    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canPlace(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int stalls[] = {1, 2, 4, 8, 9};
    int n = 5;
    int k = 3;
    int dist = maxMinDistance(stalls, n, k);
    printf("Maximum minimum distance: %d\n", dist);
    return 0;
}
