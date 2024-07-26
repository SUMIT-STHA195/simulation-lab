// Implementation of gap test function in c programming
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to calculate the theoretical CDF
double theoretical_cdf(double x) {
    return 1 - pow(0.9, x + 1);
}

// Function to sort an array
void sort_array(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Function to calculate the empirical CDF
double empirical_cdf(int *gaps, int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (gaps[i] <= x) {
            count++;
        }
    }
    return (double)count / size;
}

int main() {
    int n, target, max_gap;
    double alpha, D_alpha;

    // Input sequence size
    printf("Enter the number of elements in the sequence: ");
    scanf("%d", &n);

    int sequence[n];

    // Input sequence values
    printf("Enter the sequence values: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // Input target value
    printf("\nEnter the target value: ");
    scanf("%d", &target);

    // Input maximum gap to count
    printf("Enter the maximum gap to count: ");
    scanf("%d", &max_gap);

    // Input significance level alpha
    printf("Enter the significance level alpha (e.g., 0.05): ");
    scanf("%lf", &alpha);

    // Input critical value D_alpha from KS table
    printf("Enter the critical value D_alpha: ");
    scanf("%lf", &D_alpha);

    int gaps[n];
    int gap_counts[max_gap + 1];

    // Initialize gaps and gap_counts arrays to 0
    for (int i = 0; i < n; i++) {
        gaps[i] = 0;
    }
    for (int i = 0; i <= max_gap; i++) {
        gap_counts[i] = 0;
    }

    // Perform gap test
    int gap = 0;
    int gap_index = 0;
    for (int i = 0; i < n; i++) {
        if (sequence[i] == target) {
            if (gap > 0) {
                if (gap <= max_gap) {
                    gap_counts[gap]++;
                } else {
                    gap_counts[max_gap]++;
                }
                gaps[gap_index++] = gap;
                gap = 0;
            }
        } else {
            gap++;
        }
    }

    // Sort the gaps array
    sort_array(gaps, gap_index);

    // Calculate D
    double D = 0.0;
    printf("\nCalculations:\n");
    printf(" x |   F(x)   |  S_N(x)  | |F(x) - S_N(x)|\n");
    printf("---|----------|----------|---------------\n");
    for (int i = 0; i <= max_gap; i++) {
        double F_x = theoretical_cdf(i);
        double S_N_x = empirical_cdf(gaps, gap_index, i);
        double D_current = fabs(F_x - S_N_x);
        printf("%2d   %8.6lf   %8.6lf   %13.6lf\n", i, F_x, S_N_x, D_current);
        if (D_current > D) {
            D = D_current;
        }
    }

    // Output the maximum deviation D
    printf("\nMaximum Deviation D: %lf\n", D);

    // Determine whether to reject the null hypothesis
    if (D < D_alpha) {
        printf("D_cal < D_alpha, Null hypothesis is not rejected.\n");
    } else {
        printf("D_cal >= D_alpha, Null hypothesis is rejected.\n");
    }

    return 0;
}