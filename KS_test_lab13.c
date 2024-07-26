#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare two doubles for qsort
int compare(const void *a, const void *b) {
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) - (diff < 0);
}

// Function to perform the KS test
double ks_test(double* sample, int n) {
    qsort(sample, n, sizeof(double), compare);

    double d_plus = -1.0, d_minus = -1.0;

    printf("| %4s | %6s | %8s | %8s | %15s | %15s |\n", "i", "Ri", "i/n", "(i-1)/n", "D+ = i/n - Ri", "D- = Ri - (i-1)/n");
    printf("|------|--------|----------|----------|-----------------|-----------------|\n");

    for (int i = 0; i < n; i++) {
        double ri = sample[i];
        double d_plus_i = (i + 1.0) / n - ri;
        double d_minus_i = ri - i / (double)n;

        printf("| %4d | %6.2f | %8.2f | %8.2f | %15.2f | %15.2f |\n", i + 1, ri, (i + 1.0) / n, i / (double)n, d_plus_i, d_minus_i);

        if (d_plus_i > d_plus) {
            d_plus = d_plus_i;
        }
        if (d_minus_i > d_minus) {
            d_minus = d_minus_i;
        }
    }

    printf("D+ = %f, D- = %f\n", d_plus, d_minus);
    return fmax(d_plus, d_minus);
}

// Function to get the critical value from the KS table (simplified)
double ks_critical_value(int n, double alpha) {
    // Simplified critical values for common alpha levels
    if (alpha == 0.1) return 1.22 / sqrt(n);
    if (alpha == 0.05) return 1.36 / sqrt(n);
    if (alpha == 0.01) return 1.63 / sqrt(n);
    return -1.0; // Invalid alpha
}

int main() {
    int n;
    double alpha;

    // Get the sample size
    printf("Enter the sample size: ");
    scanf("%d", &n);

    // Allocate memory for the sample
    double* sample = (double*)malloc(n * sizeof(double));
    if (sample == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the sample values
    printf("Enter the sample values:\n");
    for (int i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        scanf("%lf", &sample[i]);
    }

    // Get the significance level
    printf("Enter the significance level (e.g., 0.05): ");
    scanf("%lf", &alpha);

    // Perform the KS test
    double d = ks_test(sample, n);
    double d_alpha = ks_critical_value(n, alpha);

    // Print the results
    printf("D calculated: %f\n", d);
    printf("D critical (alpha = %f): %f\n", alpha, d_alpha);

    // Decision rule
    if (d < d_alpha) {
        printf("Since D calculated < critical value, Do not reject the null hypothesis (H0)\n");
    } else {
        printf("Reject the null hypothesis (H0)\n");
    }

    // Free the allocated memory
    free(sample);

    return 0;
}