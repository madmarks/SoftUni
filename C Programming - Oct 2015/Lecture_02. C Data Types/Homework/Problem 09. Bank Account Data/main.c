#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/*
 * A bank account has a holder name (first name, middle name and last name), 
 * available amount of money (balance), bank name, IBAN and 3 credit card 
 * numbers associated with the account. Declare the variables needed to keep 
 * the information for a single bank account using the appropriate data 
 * types and descriptive names.
 */
int main() 
{
    char *firstName = "Tomas";
    char *middleName = "Enrique";
    char *lastName = "Araya";
    long double balance = 0.0123456789;
    char *bankName = "FIBank";
    
    // IBAN consists of up to 34 alphanumeric characters
    char iban[35] = "GR1601101250000000012300695";
    uint64_t creditCardNumbers[3] = {1234567890123456, 5678901234567890, 9012345678901234};
    
    printf("First name: %s\n", firstName);
    printf("Middle name: %s\n", middleName);
    printf("Last name: %s\n", lastName);
    printf("Balance: %.10llf\n", balance);
    printf("Bank name: %s\n", bankName);
    
    printf("1-st credit card number: %"PRIu64"\n", creditCardNumbers[0]);
    printf("2-nd credit card number: %"PRIu64"\n", creditCardNumbers[1]);
    printf("3-rd credit card number: %"PRIu64"\n", creditCardNumbers[2]);
    
    return (EXIT_SUCCESS);
}

