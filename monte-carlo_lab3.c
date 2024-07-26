//3. WAP to compute PI using Monte Carlo method using C programming language.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TOTAL_POINTS 1000000

int main() {
    int inside_circle = 0;
    double x, y;

    // Seed for random number generation
    srand(time(NULL));

    for (int i = 0; i < TOTAL_POINTS; i++) {
        // Generate random coordinates in the range [-1, 1]
        x = ((double)rand() / RAND_MAX) * 2 - 1;
        y = ((double)rand() / RAND_MAX) * 2 - 1;

        // Check if the point is inside the unit circle
        if (sqrt(x * x + y * y) <= 1)
            inside_circle++;
    }

    // Approximate π using the ratio of points inside the circle to the total points
    double pi = (double)inside_circle / TOTAL_POINTS * 4;

    printf("Approximated value of PI using Monte Carlo method: %.10f\n", pi);

    return 0;
}