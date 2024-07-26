/*WAP to use mixed congruential method to generate a sequence of 10 five-digit random integers and corresponding random variables. Let x0 = 4, a=3 and c=2.*/
#include <stdio.h>

int main() {
    int m = 100000;  // modulus to ensure five-digit integers
    int a = 3;       // multiplier
    int c = 2;       // increment
    int X0 = 4;      // initial seed
    int Xi = X0;     // current value

    printf("Random Integer    Random Variable\n");
    printf("---------------------------------\n");
    for (int i = 0; i < 10; i++) {
        Xi = (a * Xi + c) % m;  // Mixed congruential formula
        double random_variable = (double) Xi / m;  // Normalize to get random variable in [0, 1)
        printf("%05d            %.5f\n", Xi, random_variable);  // Print results in columns
    }

    return 0;
}