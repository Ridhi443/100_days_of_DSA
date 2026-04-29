// Problem Statement: Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    
    // Count frequency of each character
    for(int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    
    // Find first character with frequency 1
    for(int i = 0; i < len; i++) {
        if(count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }
    
    return '$';
}

int main() {
    char s[] = "abccba";
    char res = firstNonRepeatingChar(s);
    if(res != '$') {
        printf("First non-repeating character: %c\n", res);
    } else {
        printf("No non-repeating character\n");
    }
    return 0;
}
