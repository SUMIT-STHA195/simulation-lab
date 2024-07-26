/*WAP to use MUltiplicative congruential method to generate a sequence of 10 three-digit random integers and corresponding random variables.Let X0=5,a=3 and c=2*/
#include <stdio.h>

int main() {
    int m = 1000;  // modulus to ensure three-digit integers
    int a = 3;     // multiplier
    int X0 = 5;    // initial seed
    int Xi = X0;   // current value

    printf("Random Integer   Random Variable\n");
    printf("---------------------------------\n");
    for (int i = 0; i < 10; i++) {
        Xi = (a * Xi) % m;  // Multiplicative congruential formula
        double random_variable = (double) Xi / m;  // Normalize to get random variable in [0, 1)
        printf("%03d              %.3f\n", Xi, random_variable);  // Print results in columns
    }

    return 0;
}