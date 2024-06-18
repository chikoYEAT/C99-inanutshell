// program which calculates number of digits in an integer
#include <stdio.h>
int main(void) {
    int digits = 0, n;
    printf("ENter non neg digit: ");
    scanf("%d",&n);

    
    do {
        n /=10;
        digits ++;
    } while (n>0);

    printf("number of digits are : %d \n", digits);
    return 0;
}