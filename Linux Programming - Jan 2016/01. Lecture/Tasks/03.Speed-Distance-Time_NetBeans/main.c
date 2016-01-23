#include <stdio.h>
#include <inttypes.h>

/*
 * 1. Write a C program that calculates 
 *    1.1 Speed by given Acceleration and time after the start of 
 *        the acceleration
 *    1.2 Distance by given Acceleration and time after the start of 
 *        the acceleration
 *    1.3 Time to stop if the car has deceleration equal to Acceleration 
 *        divided by 2, by given time and Distance
 * 
 * 2. Create a makefile
 * 3. Compile and run
 * 
 * For 1 and 2
 *    - Acceleration = 10 m/s^2
 *    - Time = 2 min
 * 
 * For 3
 *    - Distance is 12100 m
 *    - Time is 110 s 
 */
int main() {

    int acceleration = 10; // meters/second^2
    int time = 2;          // minutes
    
    int distance = 12100;  // meters
    int time_t3 = 110;     // seconds
    
    // task 1.1 -> v = a * t
    uint64_t speed_t1 = acceleration * (time * 60); // m/s
    
    // task 1.2 -> S = (a * t^2) / 2 = (v * t) / 2
    uint64_t distance_t2 = speed_t1 * (time * 60) / 2; // m
    
    // task 1.3
    long double speed_t3 = distance / time_t3;
    long double acceleration_t3 = speed_t3 / time_t3; // m/s^2
    long double deceleration_t3 = acceleration_t3 / 2; // m/s^2
    long double time_to_stop_t3 = speed_t3 / deceleration_t3; // s
    
    printf("Task 1 -> speed = %"PRIu64" m/s\n", speed_t1);
    printf("Task 1 -> speed = %.2Lf km/h\n\n", speed_t1 * (3600.0L / 1000.0L));
    
    printf("Task 2 -> distance = %"PRIu64" m\n", distance_t2);
    printf("Task 2 -> distance = %.3Lf km\n\n", distance_t2 / 1000.0L);
    
    printf("Task 3 -> time_to_stop = %.2Lf s\n", time_to_stop_t3);
    printf("Task 3 -> time_to_stop = %.3Lf h\n", time_to_stop_t3 / 3600.0L);
    
    return 0;
}

