// check palindrome string.
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int isPalindrome=1;
    printf("enter the string: ");
    scanf("%s",str);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
        if (str[i] != str[len - i - 1]) 
            isPalindrome=0;
           
    }
    if (isPalindrome) 
        printf("YES\n");
    else 
        printf("NO\n");
        return 0;
}