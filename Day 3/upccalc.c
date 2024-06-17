#include <stdio.h>


int main() {
    int d, i1, i2,i3,i4,i5,j1,j2,j3,j4,j5, first;
    int  second,total,remainder;
    printf("Enter first:");
    scanf("%d", &d);
    printf("Enter firstfive");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3,&i4,&i5);
    printf("Enter next five");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3,&j4,&j5);
    first = d +i2 + i4 + j1+ j3 +j5;
    second = i1 + i3 + i5 +j2+j4;
    total = first*3+second;
    printf("%d\n",9-((total-1)%10));
    return 0;
}