#include <stdio.h>

int main() {
    int a = 9;
    switch (a) {
        case 9: printf("Equal\n") ;
                break;
        case 3: printf("Good\n") ; 
                break;
        case 2: printf("Average") ;
                break;
        case 1: printf("fail") ;
                break;
        default : printf("illegal") ;
                break;
    }
    return 0;
}
// case value can't be a declaration  
//  for example it shoulb be int
// break should be used to about repeatations 