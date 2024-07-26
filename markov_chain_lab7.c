/*WAP to implement Stock Market Problem:
Market up today  
	⇒ 50% chance of market up tomorrow
	⇒ 50% chance of market down tomorrow
Market down today  
⇒ 30% chance of market up tomorrow
⇒ 70% chance of market down tomorrow
What will be the probability if the market is down today that the market will be down the day after tomorrow?*/
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
        {0.50, 0.50}, // P(up tomorrow | up today), P(down tomorrow | up today)
        {0.30, 0.70}  // P(up tomorrow | down today), P(down tomorrow | down today)
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
    double initial[2] = {0.0, 1.0}; // Market down today

    // Probability vector for the day after tomorrow
    double day_after_tomorrow[2];

    // Calculate probability for the day after tomorrow using P * P
    day_after_tomorrow[0] = initial[0] * PP[0][0] + initial[1] * PP[1][0]; // P(up day after tomorrow)
    day_after_tomorrow[1] = initial[0] * PP[0][1] + initial[1] * PP[1][1]; // P(down day after tomorrow)

    // Print the P * P matrix
    printf("Transition matrix P * P:\n");
    printMatrix(PP);

    // Print the result
    printf("Probability that the market will be down the day after tomorrow if it is down today: %f\n", day_after_tomorrow[1]);

    return 0;
}