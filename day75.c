// Problem Statement: Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <string.h>

#define SUM_OFFSET 10000
#define SUM_MAX 20001

int longestZeroSumSubarray(int arr[], int n) {
    int map[SUM_MAX];
    memset(map, -1, sizeof(map));
    int prefix = 0;
    int maxLen = 0;
    map[prefix + SUM_OFFSET] = -1;
    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        int idx = prefix + SUM_OFFSET;
        if(idx >= 0 && idx < SUM_MAX && map[idx] != -1) {
            int len = i - map[idx];
            if(len > maxLen) maxLen = len;
        } else {
            map[idx] = i;
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2, -4};
    int n = 7;
    int len = longestZeroSumSubarray(arr, n);
    printf("Longest subarray with sum 0: %d\n", len);
    return 0;
}
