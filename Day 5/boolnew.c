#include <stdio.h>
#include <stdbool.h>

int main(void){
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter the num:");
    scanf("%ld",&n);

    while(n>0) {
        digit = n%10;
        if (digit_seen[digit]){
            break;
        }
        digit_seen[digit]=true;
        n /= 10;
    }
    if (n>0){
        printf("repeated digits");
    } else {
        printf("Non repeated");
    }
    return 0;

}