#include <stdio.h>
/*#define N 5


int main(void) {
    int a[N],i;
    printf("Enter %d Numbers:",N);
    for (i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    printf("In reverse:");
    for(i=N-1;i>=0;i--){
        printf("%d",a[i]);
    printf("\n");                              #issue since both printf and return are in a loop

    return 0;
    }
}
*/
#define N 10
int main(void)
{
int a [N] , i;
printf ( "Enter %d numbers:",N);
for (i = 0; i < N; i++){
scanf("%d", &a[i]);
}
printf("In reverse order:");
for (i = N - 1; i >= 0; i--)
{printf(" %d", a[i]);}
printf("\n") ;
return 0;
}