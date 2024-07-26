/*Implement KS test in C programming*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* a, const void* b) {
    double arg1 = *(const double*)a;
    double arg2 = *(const double*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

double ks_test(double* data, int n, double cdf(double)) {
    // Sort the data in ascending order
    qsort(data, n, sizeof(double), compare);

    // Calculate the empirical CDF
    double* ecdf = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        ecdf[i] = (double)(i + 1) / n;
    }

    // Calculate the maximum absolute difference between the empirical CDF and the theoretical CDF
    double max_diff = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = fabs(ecdf[i] - cdf(data[i]));
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    // Clean up and return the result
    free(ecdf);
    return max_diff;
}

double my_cdf(double x) {
    // Define your own cumulative distribution function here
    // Example: return 1.0 - exp(-x);
}

int main() {
    // Example usage
    double data[] = {1.2, 2.5, 3.7, 4.9, 5.1};
    int n = sizeof(data) / sizeof(data[0]);

    double result = ks_test(data, n, my_cdf);
    printf("KS test result: %f\n", result);

    return 0;
}