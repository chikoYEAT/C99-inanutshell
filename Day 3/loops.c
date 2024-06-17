#include <stdio.h> 

int tableofsquares() {
    int entries;
    printf("Program will print a table of squares");
    scanf("%d",&entries);
    int i = 1;
    while (i<=entries+1) {
        printf("%10d%10d\n", i , i * i);
        i++ ;
    }
    return 0;
}

int sumofnumbers() {

    int num, total = 0;
    printf("Enter numbers (with whitespaces):\n");


    while (scanf("%d", &num) == 1) {
        total += num;
    }

    printf("The sum of the numbers is: %d\n", total);
    return 0;

}

int main() {
    //tableofsquares();
    sumofnumbers();
}