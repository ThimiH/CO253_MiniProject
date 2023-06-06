/*
Contact data mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

// Include required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInterface.h"                  // Links the User interfase.h file

// Define constant for the maximum sizes of data
#define NAME_SIZE 100
#define NUMBER_SIZE 20
#define ADDRESS_SIZE 300
#define EMAIL_SIZE 40
#define BIRTH_SIZE 15

// Structure of contacts
typedef struct contact{
    char name[NAME_SIZE];
    char number[NUMBER_SIZE];
    char address[ADDRESS_SIZE];
    char email[EMAIL_SIZE];
    char date[BIRTH_SIZE];
    struct contact *next;                   // Contact pointer to make this a linked list
} contact;

// Structure of contact list
typedef struct contactList{
    int index;
    contact *ptr;
} contactList;

// Predefine required functions
void deleteContact(contact *);
void editContact(contact *);

// Define the global variables
contact *head_contact = NULL, *current_contact = NULL;  //head of the linked list
int contact_count = 0;

// Loads contacts from the csv at the beginning
void loadContactsFromCSV(){
    head_contact = NULL;
    FILE *fptr = fopen("Contacts.csv","r");             // Open the data file
    if (fptr==NULL){                                    // Create a new data file if there is no such file
        fptr = fopen("Contacts.csv","w");
        fprintf(fptr, "NAME,PHONE_NUMBER,ADDRESS,EMAIL_ADDRESS,DATE_OF_BIRTH\n");
        fclose(fptr);
        fptr = fopen("Contacts.txt","r");               // Open the file again in read mode
    }
    contact cont, *node;                                // Pointers to contact to store the reading line
    while (fscanf(fptr, "%[^,],%[^,],%[^,],%[^,],%s\n", cont.name,cont.number,cont.address,cont.email,cont.date)>0)
    // Read lines and store in new node until the data file end.
    {
        node = (contact*) malloc(sizeof(contact));      // Allocate memory and store the contact in the heap memory
        strcpy(node->name,cont.name);
        strcpy(node->number,cont.number);
        strcpy(node->address,cont.address);
        strcpy(node->email,cont.email);
        strcpy(node->date,cont.date);
        node->next = NULL;

        if (head_contact==NULL){                        // Create head node
            current_contact = head_contact = node;
        }
        else{                                           // Link nodes
            contact_count++;                            // Count contacts
            current_contact = current_contact->next = node;
        }   
    }
    fclose(fptr);                                       // Close the file
}

// Function to update the data file at the end
void saveContactsToCSV(){
    FILE *fptr = fopen("Contacts.csv","w");             // Create the file again
    contact *node = head_contact;                       // Create a temporary node
    while (node!=NULL){                                 // Update the data file
        fprintf(fptr, "%s,%s,%s,%s,%s\n", node->name,node->number,node->address,node->email,node->date);
        current_contact = node->next;
        free(node);                                     // Free the memory
        node = current_contact;
    }
    printf("\nAll contacts have been saved!!");
    delay(2);                                           // Wait before exit
    system("cls");                                      // Clear the screen
}

// Function to add new contact
void addNewContact(){
    addNewDisplay();                                    // Shows the topic
    contact *newContact;
    newContact = (contact*) malloc(sizeof(contact));    // Allocate memory for new contact

    printf("-> Enter the Name \n  -> ");                // Get the data and store to the new contact pointer
    fflush(stdin);
    scanf("%[^\n]%*c",newContact->name);
    printf("-> Enter the Phone Number \n  -> ");
    fflush(stdin);
    scanf("%[^\n]s",newContact->number);
    printf("-> Enter the Address ( Without Commas (,) ) \n  -> ");
    fflush(stdin);
    scanf("%[^\n]s",newContact->address);
    printf("-> Enter the e-mail address \n  -> ");
    fflush(stdin);
    scanf("%[^\n]s",newContact->email);
    printf("-> Enter the date of birth (DD/MM/YYYY) \n  -> ");
    fflush(stdin);
    scanf("%[^\n]s",newContact->date);
    newContact->next = NULL;
    
    current_contact = head_contact;
    while (current_contact->next!=NULL){                // Traverse through the linked list to find where to include the new contact
        if(strcmp(current_contact->next->name,newContact->name)>0){
            newContact->next=current_contact->next;     // Add the contact to alphabatically corret place
            current_contact->next=newContact;           // Link to next contact
            break;
        }
        current_contact = current_contact->next;
    }
    if(newContact->next==NULL){
        current_contact->next=newContact;               // In case, add to the tail of the list
    }
    contact_count++;
    printf("\nContact saved successfully! \n\n");
    delay(2);                                           // Indicate saved and wait 
}

// Function to display a contact
void displayContact(contact * prev){            // Give the pointer to the previous contact (It is important when deleting it)
    contact * node = prev->next;                // Get the required contact
    system("cls");                              // Clear the display and display the contact
    printf("---------------------------------------------------------------------------------\n",node->name);
    printf("                                 CONTACT DETAILS\n",node->name);
    printf("---------------------------------------------------------------------------------\n\n",node->name);
    printf("  NAME          -> %s\n",node->name);
    printf("  NUMBER        -> %s\n",node->number);
    printf("  ADDRESS       -> %s\n",node->address);
    printf("  EMAIL         -> %s\n",node->email);
    printf("  DATE OF BIRTH -> %s\n\n",node->date);

    switch(contactOptions()){                   // switch between contact options
        case 0:
            break;
        case 1:
            editContact(prev);
            break;
        case 2:
            deleteContact(prev);
            break;
        default:
            invalidCommand();
    }
}

// Function to delete a contact
void deleteContact(contact * prev){             // This gets the pointer to the previous contact
    contact * node = prev->next;                // Get the contact to delete
    prev->next = node->next;                    // Bypass the contact from linked list
    free(node);                                 // Free the memory
    printf("Contact Deleted!\n");
    contact_count--;                            // Edit number of contacts
    delay(2);                                   // Wait before returning
}

// Edit contact function
void editContact(contact * prev){
    contact *node = prev->next;                 // Create a pointer to the contact to edit
    switch(editOptions()){                      // Move to the required field to edit and edit
        case 0:
            break;
        case 1:                                             // Change name
            printf("\n -> Enter the new name \n -> ");
            fflush(stdin);                                  // Clear inputs
            scanf("%[^\n]%*c",node->name);                  // Get the input
            printf(" -> Succsessfully changed \n -> ");
            delay(2);                                       // Display the massege for 2 sec
            break;
        case 2:                                             // Change number
            printf("\n -> Enter the new number \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->number);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        case 3:                                             // Change address
            printf("\n -> Enter the new address \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->address);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        case 4:                                             // Change email
            printf("\n -> Enter the new e-mail \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->email);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        case 5:                                             // Change date of birth
            printf("\n -> Enter the new date of birth (DD/MM/YYYY) \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->date);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        default:
            invalidCommand();
    }
}

// Search by name
void searchByName(){
    contact *node;                                      // Temporary Pointer
    current_contact = head_contact;                     // Begin the search from the head
    contactList contList[contact_count];                // Create an array of contactList structures
    int ind = 1;                                        // Number of contact

    char searchName[NAME_SIZE];                         // This part gets the string to search
    system("cls");
    printf("\n---------------------------\n");
    printf("Enter the name below\n");
    printf("---------------------------\n\n -> ");
    fflush(stdin);
    scanf("%[^\n]s",searchName);

    // This loops through contacts and stores the pointers of the previous contact in the array if matching
    while(current_contact->next->next!=NULL){
        node = current_contact->next;
        if(strstr(node->name,searchName)!=NULL){
            contList[ind-1].index = ind++;
            contList[ind-2].ptr = current_contact;
        }
        current_contact = node;
    }
    printf("%d contact(/s) found!\n\n",ind-1);
    for (int i=0; i<ind-1;i++){                         // Display contacts
        printf("%d - %s\n",contList[i].index,contList[i].ptr->next->name);
    }
    printf("\n---------------------------\n");          // Get the number of contact to open
    printf(" ENTER OPTION  [0-%d] \n",ind-1);
    printf(" -> 0 to go home. \n -> Other to view contact.\n");
    printf("---------------------------\n");
    fflush(stdin);
    int command;
    scanf("%d",&command);
    if (command==0){                                    // Return to menu
    }
    else if(1<=command<ind){                            // Display the regarding contact
        displayContact(contList[command-1].ptr);
    }
    else{                                               // Show if the command is invalid
        invalidCommand();
    }
}

// Search by name
void searchByNumber(){
    contact *node;                                      // Temporary Pointer
    current_contact = head_contact;                     // Begin the search from the head
    contactList contList[contact_count];                // Create an array of contactList structures
    int ind = 1;                                        // Number of contact

    char searchNumber[NUMBER_SIZE];                     // This part gets the number to search
    system("cls");
    printf("\n---------------------------\n");
    printf("Enter the number below\n");
    printf("---------------------------\n\n -> ");
    fflush(stdin);
    scanf("%[^\n]s",searchNumber);

    // This loops through contacts and stores the pointers of the previous contact in the array if matching
    while(current_contact->next->next!=NULL){
        node = current_contact->next;
        if(strstr(node->number,searchNumber)!=NULL){
            contList[ind-1].index = ind++;
            contList[ind-2].ptr = current_contact;
        }
        current_contact = node;
    }
    printf("%d contact(/s) found!\n\n",ind-1);
    for (int i=0; i<ind-1;i++){                         // Display contacts
        printf("%d - %s\n",contList[i].index,contList[i].ptr->next->name);
    }
    printf("\n---------------------------\n");          // Get the number of contact to open
    printf(" ENTER OPTION  [0-%d] \n",ind-1);
    printf("  -> 0 to go home. \n  -> Other to view contact.\n");
    printf("---------------------------\n");
    fflush(stdin);
    int command;
    scanf("%d",&command);
    if (command==0){                                    // Return to menu
    }
    else if(1<=command<ind){                            // Display the regarding contact
        displayContact(contList[command-1].ptr);
    }
    else{                                               // Show if the command is invalid
        invalidCommand();
    }
}

// List all contacts
void listDownContacts(){
    current_contact = head_contact;             // Start from the beginning
    contactList contList[contact_count]; 
    int ind = 1;
    system("cls");
    printf("\n---------------------------\n");
    printf("       Contact List\n");
    printf("---------------------------\n");
    for (int i=0; i<contact_count; i++){        // Display contact names with a number and store pointers is contact list to use later
        contList[i].index=i+1;
        contList[i].ptr = current_contact;
        current_contact=current_contact->next;
        printf("%d - %s\n",contList[i].index,contList[i].ptr->next->name);
    }
    printf("\n---------------------------\n");  // Open a contact
    printf(" ENTER OPTION  [0-%d] \n",contact_count);
    printf("  -> 0 to go home. \n  -> Other to view contact.\n");
    printf("---------------------------\n");
    fflush(stdin);
    int command;
    scanf("%d",&command);
    if (command==0){
    }
    else if(1<=command<contact_count){          // Display the requested contact
        displayContact(contList[command-1].ptr);
    }
    else{
        invalidCommand();
    }
}
