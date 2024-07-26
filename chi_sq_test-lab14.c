#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the Chi-Square statistic
double chi_square_statistic(int *observed, double *expected, int size) {
    double chi_square = 0.0;
    for (int i = 0; i < size; i++) {
        double difference = observed[i] - expected[i];
        chi_square += (difference * difference) / expected[i];
    }
    return chi_square;
}

int main() {
    int num_categories;
    double alpha, critical_value;

    // Input number of categories
    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    int observed[num_categories];
    double expected[num_categories];

    // Input observed frequencies
    printf("Enter the observed frequencies:\n");
    for (int i = 0; i < num_categories; i++) {
        scanf("%d", &observed[i]);
    }

    // Input expected frequencies
    printf("Enter the expected frequencies:\n");
    for (int i = 0; i < num_categories; i++) {
        scanf("%lf", &expected[i]);
    }

    // Input significance level alpha
    printf("Enter the significance level alpha (e.g., 0.05): ");
    scanf("%lf", &alpha);

    // Input critical value from Chi-Square distribution table
    printf("Enter the critical value from the Chi-Square distribution table: ");
    scanf("%lf", &critical_value);

    // Calculate Chi-Square statistic
    double chi_square = chi_square_statistic(observed, expected, num_categories);

    // Output calculations
    printf("\nCalculations:\n");
    printf(" Category | Observed | Expected | (Observed - Expected)^2 / Expected\n");
    printf("----------|----------|----------|-----------------------------------\n");

    for (int i = 0; i < num_categories; i++) {
        double difference = observed[i] - expected[i];
        double chi_square_contribution = (difference * difference) / expected[i];
        printf("%9d | %8d | %8.2lf | %30.2lf\n", i + 1, observed[i], expected[i], chi_square_contribution);
    }

    printf("\nChi-Square Statistic: %lf\n", chi_square);

    // Determine whether to reject the null hypothesis
    if (chi_square < critical_value) {
        printf("Chi-Square statistic < Critical value, Null hypothesis is not rejected.\n");
    } else {
        printf("Chi-Square statistic >= Critical value, Null hypothesis is rejected.\n");
    }

    return 0;
}