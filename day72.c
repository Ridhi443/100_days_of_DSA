// Problem Statement: Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>
#include <string.h>
#include <limits.h>

char firstRepeatedChar(char* s) {
    int first[26];
    memset(first, -1, sizeof(first));
    int minIndex = INT_MAX;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if(first[c] != -1) {
            if(i < minIndex) {
                minIndex = i;
            }
        } else {
            first[c] = i;
        }
    }
    if(minIndex == INT_MAX) {
        return '\0';
    } else {
        return s[minIndex];
    }
}

int main() {
    char s[] = "abca";
    char res = firstRepeatedChar(s);
    if(res != '\0') {
        printf("First repeated character: %c\n", res);
    } else {
        printf("No repeated character\n");
    }
    return 0;
}
