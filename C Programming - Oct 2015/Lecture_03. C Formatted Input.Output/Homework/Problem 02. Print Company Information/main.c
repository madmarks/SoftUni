#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_LENGTH 100

/*
 * Problem 02. Print Company Information
 * 
 * A company has name,  address,  phone number,  fax  number,  web site and 
 * manager. The manager has first name, last name, age and a phone number. 
 * Write a program that reads the information about a company and its 
 * manager and prints it back on the console.
 */
int main() 
{
    char companyName[BUFFER_LENGTH];
    char companyAddress[BUFFER_LENGTH];
    char companyPhoneNumber[BUFFER_LENGTH];
    char companyFaxNumber[BUFFER_LENGTH];
    char companyWebSiteAddress[BUFFER_LENGTH];
    char managerFirstName[BUFFER_LENGTH];
    char managerLastName[BUFFER_LENGTH];
    unsigned short managerAge;
    char managerPhoneNumber[BUFFER_LENGTH];
    
    char buffer[BUFFER_LENGTH];
    int length;
    
    printf("\nInput company name: ");
    if(NULL == fgets(companyName, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(companyName);
        if(length > 0 && companyName[length - 1] == '\n')
            companyName[length - 1] = '\0';
    }
    
    printf("Input company address: ");
    if(NULL == fgets(companyAddress, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(companyAddress);
        if(length > 0 && companyAddress[length - 1] == '\n')
            companyAddress[length - 1] = '\0';
    }
    
    printf("Input company phone number: ");
    if(NULL == fgets(companyPhoneNumber, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(companyPhoneNumber);
        if(length > 0 && companyPhoneNumber[length - 1] == '\n')
            companyPhoneNumber[length - 1] = '\0';
    }
    
    printf("Input company fax number: ");
    if(NULL == fgets(companyFaxNumber, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(companyFaxNumber);
        if(length > 0 && companyFaxNumber[length - 1] == '\n')
            companyFaxNumber[length - 1] = '\0';
    }
    
    printf("Input company Web site address: ");
    if(NULL == fgets(companyWebSiteAddress, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(companyWebSiteAddress);
        if(length > 0 && companyWebSiteAddress[length - 1] == '\n')
            companyWebSiteAddress[length - 1] = '\0';
    }
    
    printf("Input manager first name: ");
    if(NULL == fgets(managerFirstName, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(managerFirstName);
        if(length > 0 && managerFirstName[length - 1] == '\n')
            managerFirstName[length - 1] = '\0';
    }
    
    printf("Input manager last name: ");
    if(NULL == fgets(managerLastName, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(managerLastName);
        if(length > 0 && managerLastName[length - 1] == '\n')
            managerLastName[length - 1] = '\0';
    }
    
    printf("Input manager age: ");
    if(NULL == fgets(buffer, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    errno = 0;
    managerAge = strtol(buffer, NULL, 10);
    if(errno != 0 || managerAge <=0 || managerAge > 150)
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    
    printf("Input manager phone number: ");
    if(NULL == fgets(managerPhoneNumber, BUFFER_LENGTH, stdin))
    {
        printf("Error!");
        return (EXIT_FAILURE);
    }
    else
    {
        /* Remove trailing newline, if any */
        length = strlen(managerPhoneNumber);
        if(length > 0 && managerPhoneNumber[length - 1] == '\n')
            managerPhoneNumber[length - 1] = '\0';
    }
    
//    // *** for testing purposes only *** //
//    
//    char *companyName = "Software University";
//    char *companyAddress = "15-18 Tintyava, Sofia";
//    char *companyPhoneNumber = "+359 899 55 55 92";
//    char *companyFaxNumber = "";
//    char *companyWebSiteAddress = "http://softuni.bg";
//    char *managerFirstName = "Svetlin";
//    char *managerLastName = "Nakov";
//    unsigned short managerAge = 25;
//    char *managerPhoneNumber = "+359 2 981 981";
    
    printf("\n\n%s\n", companyName);
    printf("Address: %s\n", companyAddress);
    printf("Tel. %s\n", companyPhoneNumber);
    printf("Fax: %s\n", companyFaxNumber);
    printf("Web site: %s\n", companyWebSiteAddress);
    printf("Manager: %s %s ", managerFirstName, managerLastName);
    printf("(age: %d, tel. %s)\n", managerAge, managerPhoneNumber);

    return (EXIT_SUCCESS);
}

