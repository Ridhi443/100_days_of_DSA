// reverse a string.
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("enter the string: ");
    scanf("%s",str);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
       char temp = str[i];
       str[i] = str[len - i - 1];
       str[len - i - 1] = temp;
    }
           
    printf("reversed string: %s\n", str);
    
        return 0;
}
