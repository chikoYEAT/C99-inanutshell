#include <stdio.h>
#include <time.h>

void print_count(int n){
    printf("T minus %d and counting\n",n);
}

void delay(int number_of_seconds)
{

    int milli_seconds = 500000 * number_of_seconds;
 

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

int main(void){
    int i;
    for (i=10;i>0;--i){
        delay(1);
        print_count(i);
    }
    return 0;
}