/*Implementation of autocorrelation function in c programming*/
#include <stdio.h>

// Function to generate random numbers using the Multiplicative Congruential Method
void generateRandomNumbers(int X[], int n, int m, int a, int X0)
{
    int i;
    X[0] = X0;
    for (i = 1; i < n; i++)
    {
        X[i] = (a * X[i - 1]) % m;
    }
}

// Function to calculate the mean of an array
double calculateMean(int X[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += X[i];
    }
    return sum / n;
}

// Function to calculate the autocorrelation
double calculateAutocorrelation(int X[], int n, int lag)
{
    double mean = calculateMean(X, n);
    double numerator = 0.0, denominator = 0.0;

    for (int i = 0; i < n - lag; i++)
    {
        numerator += (X[i] - mean) * (X[i + lag] - mean);
    }

    for (int i = 0; i < n; i++)
    {
        denominator += (X[i] - mean) * (X[i] - mean);
    }

    return numerator / denominator;
}

int main()
{
    int n = 10;   // Number of random numbers to generate
    int m = 1000; // Modulus to ensure three-digit numbers
    int a = 3;    // Multiplier
    int X0 = 5;   // Initial value
    int lag = 1;  // Lag for autocorrelation calculation
    int X[n];     // Array to store random numbers

    // Generate random numbers
    generateRandomNumbers(X, n, m, a, X0);

    // Print generated random numbers
    printf("Generated random numbers:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%03d ", X[i]);
    }
    printf("\n");

    // Calculate and print autocorrelation
    double autocorrelation = calculateAutocorrelation(X, n, lag);
    printf("Autocorrelation with lag %d: %f\n", lag, autocorrelation);

    return 0;
}