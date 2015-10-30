#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Leap year checking
int isLeapYear(int year, int month) 
{
    int flag = 0;
    if (year % 100 == 0) 
    {
        if (year % 400 == 0) 
        {
            if (month == 2) 
            {
                flag = 1;
            }
        }
    } 
    else if (year % 4 == 0) 
    {
        if (month == 2) 
        {
            flag = 1;
        }
    }
    return (flag);
}

/*
 * Write a program that reads your birthday from the console as text and 
 * prints how old you are now and how old you will be after 10 years
 */
int main() 
{
    // Days in month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  
    
    char *months[] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December",
    };
    
    unsigned int birthDay;
    unsigned int birthMonth;
    unsigned int birthYear;
    
    printf("Input your birth date (DD.MM.YYYY) : ");
    scanf("%2u.%2u.%4u", &birthDay, &birthMonth, &birthYear);
    
    if(1 <= birthDay && birthDay <= 31 
            && 1 <= birthMonth && birthMonth <= 12 
            && 1900 <= birthYear)
    {
        int remainingDaysInMonthOfBirth = daysInMonth[birthMonth - 1] - birthDay;

        // Checking if the given year is Leap or not
        if (isLeapYear(birthYear, birthMonth)) 
        {
            remainingDaysInMonthOfBirth++;
        }       
        
        time_t t = time(NULL);    
        struct tm localTime = *localtime(&t);
        
//        printf("\nCurrent date : %02d %s %4d %02d:%02d:%02d\n", 
//            localTime.tm_mday,
//            months[localTime.tm_mon],
//            localTime.tm_year + 1900,
//            localTime.tm_hour,
//            localTime.tm_min,
//            localTime.tm_sec);        
        
        // Calculating the number of year, month and date since birthday
        unsigned int daysOld = remainingDaysInMonthOfBirth + localTime.tm_mday;
        unsigned int monthsOld = (12 - birthMonth) + (localTime.tm_mon);
        unsigned int yearsOld = (localTime.tm_year + 1900) - birthYear - 1;

        if (isLeapYear((localTime.tm_year + 1900), (localTime.tm_mon + 1))) 
        {
            if (daysOld >= (daysInMonth[localTime.tm_mon] + 1)) 
            {
                daysOld = daysOld - (daysInMonth[localTime.tm_mon] + 1);
                monthsOld = monthsOld + 1;
            }
        } 
        else if (daysOld >= daysInMonth[localTime.tm_mon]) 
        {
            daysOld = daysOld - daysInMonth[localTime.tm_mon];
            monthsOld = monthsOld + 1;
        }

        if (monthsOld >= 12) 
        {
            yearsOld = yearsOld + 1;
            monthsOld = monthsOld - 12;
        }
        
//        printf("Age: %d years %d months and %d days\n", 
//                yearsOld, monthsOld, daysOld);
        
        printf("Now: %u\n", yearsOld);
        printf("After 10 years: %u\n", (yearsOld + 10));
    }
    else
    {
        printf("\nError. Incorrect birth date!\n");
        return (EXIT_FAILURE);
    }
    
    return (EXIT_SUCCESS);
}