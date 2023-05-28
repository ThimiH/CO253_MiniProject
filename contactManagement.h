/*
Contact data mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

#include <stdio.h>

#define NAME_SIZE 100
#define ADDRESS_SIZE 300
#define EMAIL_SIZE 40

typedef struct {
    char* name[NAME_SIZE];
    unsigned int number;
    char* address[ADDRESS_SIZE];
    char* email[EMAIL_SIZE];
} contact;

contact** contacts;
int* contactStatus;

void loadContactsFromCSV();

void saveContactsToCSV();

void addNewContact();

void deleteContact();

void searchByName();

void searchByContact();

void listDownContacts();

int main() {
    return 0;
}

