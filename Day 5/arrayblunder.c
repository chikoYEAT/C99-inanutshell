#include <stdio.h>

int main() {
    int a[10], i;

    for (i = 0; i <= 10; i++) {
        a[i] = 0;
        printf("x");
    }

    return 0;
}
/*this program goes in an infinite loop in some compilers*/
/*when a[i] -> a[10]*/

/*it gives output: *** stack smashing detected ***: terminated*/