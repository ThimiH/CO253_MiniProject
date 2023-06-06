/*
UI of the contact mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

// Inculde required header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to freez the screen before starting a new display session
void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;       // Converting time into milli_seconds
    clock_t start_time = clock();                       // Storing start time
    while (clock() < start_time + milli_seconds);       // looping till required time is not achieved
}

// This displays the home menu and prompt users for a command and returns the user input
int homeMenu(){
    system("cls");                                      // Clear screen
    printf("---------------------------\n");            // Display the menu
    printf(" CONTACT MANAGEMENT SYSTEM \n");
    printf("---------------------------\n\n");
    printf("0. Quit\n");
    printf("1. Add a new contact\n");
    printf("2. List all contacts\n");
    printf("3. Search for contact\n\n");
    printf("---------------------------\n");
    printf("    ENTER OPTION  [0-3] \n");
    printf("---------------------------\n");
    int command;
    fflush(stdin);                                      // Clear previous inputs to avoid errors
    scanf("%d",&command);                               // scan the command number
    return command;                                     // Returns the command
}

// This displays the search contact menu and prompt users for a command and returns the user input
int searchForContacts(int num){
    system("cls");                                      // Clear screen
    printf("---------------------------\n");            // Display the menu
    printf("    SEARCH FOR CONTACTS \n");
    printf("---------------------------\n\n");
    printf("%d saved contacts\n\n",num);
    printf("0 - SEARCH BY NAME\n");
    printf("1 - SEARCH BY NUMBER\n");
    printf("2 - BACK\n\n");
    printf("---------------------------\n");
    printf("    ENTER OPTION  [0-2] \n");
    printf("---------------------------\n");
    int command;
    fflush(stdin);                                      // Clear previous inputs to avoid errors
    scanf("%d",&command);                               // scan the command number
    return command;                                     // Returns the command
}

// Shows when an invalid command is entered
void invalidCommand(){
    printf("---------------------------\n");            // Display the massege
    printf("     INVALID COMMAND!! \n");
    printf("---------------------------\n\n");
    delay(2);                                           // Wait for 2 seconds
}

// Add new contact display
void addNewDisplay(){
    printf("---------------------------\n");            // Display the topic
    printf("      Add New Contact \n");
    printf("---------------------------\n\n");
}

// This displays the contact menu and prompt users for a command and returns the user input
int contactOptions(){
    printf("    0 - HOME\n");                           // Display the menu
    printf("    1 - EDIT CONTACT\n");
    printf("    2 - DELETE CONTACT\n\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("        ENTER OPTION  [0-2] \n");
    printf("---------------------------------------------------------------------------------\n");
    int command;
    fflush(stdin);                                      // Clear previous inputs to avoid errors
    scanf("%d",&command);                               // scan the command number
    return command;                                     // Returns the command
}

// This displays the edit contact menu and prompt users for a command and returns the user input
int editOptions(){                                      // Display the menu
    printf("---------------------------------------------------------------------------------\n");
    printf("        EDIT CONTACT \n");
    printf("---------------------------------------------------------------------------------\n");
    printf("    0 - GO BACK TO HOME\n");
    printf("    1 - EDIT NAME\n");
    printf("    2 - EDIT NUMBER\n");
    printf("    3 - EDIT ADDRESS\n");
    printf("    4 - EDIT EMAIL\n");
    printf("    5 - EDIT DATE OF BIRTH\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("        ENTER OPTION  [0-5] \n");
    printf("---------------------------------------------------------------------------------\n");
    int command;
    fflush(stdin);                                      // Clear previous inputs to avoid errors
    scanf("%d",&command);                               // scan the command number
    return command;                                     // Returns the command
}