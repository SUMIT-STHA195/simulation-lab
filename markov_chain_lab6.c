/*Health Monitoring Problem:
Healthy today
 ⇒ 90% chance of healthy tomorrow 
⇒ 10% chance of sick tomorrow 
Sick today
⇒ 40% chance of healthy tomorrow 
⇒ 60% chance of sick tomorrow
What will be the probability if the person is sick today that they will be sick the day after tomorrow?*/

#include <stdio.h>

// Function to print a 2x2 matrix
void printMatrix(double matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Transition matrix P
    double P[2][2] = {
        {0.90, 0.10}, // P(healthy tomorrow | healthy today), P(sick tomorrow | healthy today)
        {0.40, 0.60}  // P(healthy tomorrow | sick today), P(sick tomorrow | sick today)
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
    double initial[2] = {0.0, 1.0}; // Sick today

    // Probability vector for the day after tomorrow
    double day_after_tomorrow[2];

    // Calculate probability for the day after tomorrow using P * P
    day_after_tomorrow[0] = initial[0] * PP[0][0] + initial[1] * PP[1][0]; // P(healthy day after tomorrow)
    day_after_tomorrow[1] = initial[0] * PP[0][1] + initial[1] * PP[1][1]; // P(sick day after tomorrow)

    // Print the P * P matrix
    printf("Transition matrix P * P:\n");
    printMatrix(PP);

    // Print the result
    printf("Probability that the person will be sick the day after tomorrow if they are sick today: %.2f\n", day_after_tomorrow[1]);

    return 0;
}