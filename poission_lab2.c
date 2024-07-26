/* At the ticket counter of football stadium, people come in queue and purchase tickets. Arrival rate of customers is 1/min. It takes at the average 20 seconds to purchase the ticket. 
WAP in C to calculate total time spent by a sports fan to be seated in his seat,
 if it takes 1.5 minutes to reach the correct seat after purchasing the ticket. if a fan comes exactly before 2 minutes before the game starts, can sports fan expect to be seated for the kick-off?
 */
#include <stdio.h>

int main(){
    float arrivalRate = 1; //per minute
    float serviceRate = 3; //per minute

    float waitingTime = 1/(serviceRate - arrivalRate);
    float timeTakenToReachSeat = 1.5; //min

    float totalTimeTaken = waitingTime + timeTakenToReachSeat;

    printf("Average time to get the ticket plus the time to reach the correct seat is %f minutes. \n", totalTimeTaken );
    printf("Hence, the sports fan can expect to be seated for the kick-off.\n");
}