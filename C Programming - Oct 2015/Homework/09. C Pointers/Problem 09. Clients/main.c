#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Client
{
    char *name;
    int age;
    double balance;
};

_Bool name_comparator(struct Client *, struct Client *);
_Bool balance_comparator(struct Client *, struct Client *);
_Bool age_comparator(struct Client *, struct Client *);
void sort_clients(struct Client *, int, 
        _Bool (*) (struct Client *, struct Client *));
void swap(void *, void *, size_t);
void print_clients(struct Client *, int);

/*
 * Problem 09. Clients
 * 
 * Declare a struct called Client with the following members: name, age and 
 * account balance. More on structures: 
 * http://www.tutorialspoint.com/cprogramming/c_structures.htm
 * 
 * Write a function that sorts an array of clients using a specific comparator. 
 * The comparator should be another function that determines how the clients are 
 * sorted. Write comparators for sorting the clients by name, age and account
 * balance.
 * 
 * Sample Code
 * ---------------------------------------------------------
 * struct Client clients[] = { ... };
 * int clientsCount = ...;
 * sort_clients(clients, clientsCount, &name_comparator);
 * sort_clients(clients, clientsCount, &balance_comparator);
 * sort_clients(clients, clientsCount, &age_comparator);
 */
int main() 
{
    struct Client pesho = { "Pesho", 25, 3300.1 };
    struct Client gosho = { "Gosho", 38, 1255.6 };
    struct Client atanas = { "Atanas", 47, 58020.78 };
    struct Client veso = { "Veso", 39, 168.2 };
    
    struct Client clients[] = { pesho, gosho, atanas, veso };
    int clientsCount = sizeof(clients) / sizeof(struct Client);
    
    printf("\nClients sorted by Name\n--------------------------\n");
    sort_clients(clients, clientsCount, &name_comparator);
    print_clients(clients, clientsCount);
    
    printf("\nClients sorted by Balance\n--------------------------\n");
    sort_clients(clients, clientsCount, &balance_comparator);
    print_clients(clients, clientsCount);
    
    printf("\nClients sorted by Age\n--------------------------\n");
    sort_clients(clients, clientsCount, &age_comparator);
    print_clients(clients, clientsCount);

    return (EXIT_SUCCESS);
}


_Bool name_comparator(struct Client *client1, struct Client *client2)
{
    size_t len1 = strlen((*client1).name);    
    size_t len2 = strlen((*client2).name);
    
    char *name1 = (*client1).name;
    char *name2 = (*client2).name;
    
    size_t i = 0;
    size_t len = (len1 < len2) ? len1 : len2;
    
    while(i < len)
    {
        if(name1[i] < name2[i])
        {
            return false;
        }
        else if(name1[i] > name2[i])
        {
            return true;
        }
        
        i++;
    }
    
    if(len1 <= len2)
        return false;
    else
        return true;
}

_Bool balance_comparator(struct Client *client1, struct Client *client2)
{
    return (*client1).balance > (*client2).balance;
}

_Bool age_comparator(struct Client *client1, struct Client *client2)
{
    return (*client1).age > (*client2).age;
}

void sort_clients(struct Client *clients, int num_of_clients, 
        _Bool (*comparator) (struct Client *, struct Client *))
{
    size_t i;
    int newN;
    
    do
    {
        newN = 0;
        
        for(i = 1; i < num_of_clients; i++)
        {
            if(comparator(&clients[i - 1], &clients[i]))
            {
                swap(&clients[i - 1], &clients[i], sizeof(struct Client));
                
                newN = i;
            }
        }
        
        num_of_clients = newN; // best bubble sort optimization
        
    }while(newN != 0);
}

void swap(void *ptr1, void *ptr2, size_t size)
{
    void *tmp = malloc(size);
    if(NULL != tmp)
    {
        memcpy(tmp, ptr1, size);
        memcpy(ptr1, ptr2, size);
        memcpy(ptr2, tmp, size);
        
        free(tmp);
    }
}

void print_clients(struct Client *clients, int num_of_clients)
{
    size_t i = 0;
    for(i = 0; i < num_of_clients; i++)
    {
        printf("   name: %s\n", clients[i].name);
        printf("    age: %d\n", clients[i].age);
        printf("balance: %.2lf\n\n", clients[i].balance);
    }
}