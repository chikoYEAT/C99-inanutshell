#include <stdio.h>

/*1.check bal 2.widhdraw MOney 3.deposit money 4.exit */

int main(void) {
    printf("*** LINUS checkbook-balancing program *** \n");
    int cmd;
    int i = 0;
    printf("Commands:O =check balance, 1=widthdraw Money, 2=deposit Money, 3=exit ");
    float balance = 0.0f,credit,debit;

    for ( ; ; ) {
        printf ("Enter command : ") ;
        scanf ("%d", &cmd);
        switch (cmd) {
            case 2:
printf("Enter amount of credit: ");
scanf ("%f",&credit) ;
balance+= credit;
break;
case 1:
printf("Enter amount of debit: ");
scanf("%f", &debit);
balance-= debit;
break;
            case 0:
            printf("Current balance: $%0.2f\n", balance);
            break;
        case 3:
            return 0;
        default :
            printf("Commands:O =check balance, 1=widthdraw Money, 2=deposit Money, 3=exit ");
            break;
        }
    }
}