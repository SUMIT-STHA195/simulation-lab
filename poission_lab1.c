#include <stdio.h>

int main()
{
   double arrivalRate = 1.0 / 10 * 60; // customers per hour
   double serviceRate = 1.0 / 5 * 60;  // customers per hour

   // Probability that a customer will not have to wait at the counter
   double P0 = 1 - (arrivalRate / serviceRate);

   // Expected number of customers in the bank
   double ls = arrivalRate / (serviceRate - arrivalRate);

   // Expected time to be spent in the bank
   double ws = 1 / (serviceRate - arrivalRate) * 60;

   printf("Probability that a customer will not have to wait at the counter is %f.\n", P0);
   printf("Expected number of customers in the bank is %f.\n", ls);
   printf("Expected time to be spent in the bank is %f minutes.\n", ws);

   return 0;
}