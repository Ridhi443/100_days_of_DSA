// compute powers using recursion.
#include <stdio.h>
int power(int base, int exp) 
{
if (exp == 0) 
return 1;
else 
return base * power(base, exp-1);
}
int main() {
    int base,exp;
    printf("enter the base: ");
    scanf("%d",&base);
     printf("enter the exponent: ");
    scanf("%d",&exp);
    printf("result: %d",power(base,exp));
    return 0;
}
