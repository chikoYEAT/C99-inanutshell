#include <stdio.h>

int main() {
    int height, length, width;


    printf("Enter heigth:");
    scanf("%d"  , &height);
    printf("Enter length:");
    scanf("%d" , &length);
    printf("Enter width:");
    scanf("%d" , &width);
    printf("%d\n", height * length * width);
}