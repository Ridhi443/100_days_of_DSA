// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
#include <stdio.h>

int mySqrt(int n) {
    if(n == 0) return 0;

    int low = 1, high = n;
    int ans = 0;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        if(mid * mid == n)
            return (int)mid;
        else if(mid * mid < n) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", mySqrt(n));

    return 0;
}