#include <stdio.h>

int main (void)
{
    char ch;
    int len = 0;
    printf("Give msg input:",ch);
    ch = getchar();
    
    while (ch != '\n') {
        len++;
        ch= getchar();
    }
    printf("Your message was %d character(s) long.\n", len);

    return 0;
}