/*In a single pump service station, vehicles arrive for fueling with an average of 5 minutes between arrivals. If an hour is taken as unit of time, cars arrive according to Poison’s process with an average of λ= 12 cars/hr. Write a C program to generate Poisson distribution for x = 0,1,2, …. 15.*/
#include <stdio.h>
#include <math.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0)
        return 1;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    float arrivalRate = 12.0; // 12 cars/hr
    int x;

    for (x = 0; x <= 15; x++) {
        // Poisson probability mass function
        float fx = (pow(exp(1.0), -arrivalRate) * pow(arrivalRate, x)) / factorial(x);
        printf("P(X = %d) = %f\n", x, fx);
    }

    return 0;
}
