/*Weather Problem:
raining today ⇒ 40 % rain tomorrow
                                ⇒ 60 % no rain tomorrow
not raining today ⇒ 20 % rain tomorrow
                                      ⇒ 80 % no rain tomorrow
What will be probability if today is not raining then not rain the day after tomorrow?
Write a C program to find the weather of the next day by using Markov Chain Method.*/
#include <stdio.h>

int main() {
    // Transition matrix
    double P[2][2] = {
        {0.4, 0.6}, // P(rain tomorrow | rain today), P(no rain tomorrow | rain today)
        {0.2, 0.8}  // P(rain tomorrow | no rain today), P(no rain tomorrow | no rain today)
    };

    // Matrix to store P * P
    double PP[2][2];

    // Calculate P * P
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            PP[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                PP[i][j] += P[i][k] * P[k][j];
            }
        }
    }

    // Initial probabilities
    double initial[2] = {0.0, 1.0}; // Today not raining

    // Probability vector for the day after tomorrow
    double day_after_tomorrow[2];

    // Calculate probability for the day after tomorrow using P * P
    day_after_tomorrow[0] = initial[0] * PP[0][0] + initial[1] * PP[1][0]; // P(rain day after tomorrow)
    day_after_tomorrow[1] = initial[0] * PP[0][1] + initial[1] * PP[1][1]; // P(no rain day after tomorrow)

    // Print the P * P matrix
    printf("Transition matrix P * P:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", PP[i][j]);
        }
        printf("\n");
    }

    // Print the result
    printf("Probability that it will not rain the day after tomorrow if it is not raining today: %f\n", day_after_tomorrow[1]);

    return 0;
}