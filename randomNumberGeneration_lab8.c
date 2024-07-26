/*let m=100, a=19,c=0 and X0=63, and genertate a sequence random integer.
WAP to find first 7 random number generate using any suitable method?*/
#include <stdio.h>

int main(){
    int m = 100, a = 19, c = 0;
    int X[7];
    X[0] = 63;
    int i;

    printf("The first 7 random numbers are: \n");
    printf("%d\n", X[0]);

    for(i=0;i<6;i++){

    X[i+1] = (a * X[i] +c) % m;

    printf("%d\n", X[i+1]);
    }
}