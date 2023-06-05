/*
UI of the contact mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int homeMenu(){
    system("cls");
    printf("---------------------------\n");
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
    fflush(stdin);
    scanf("%d",&command);
    return command;
}

int searchForContacts(int num){
    system("cls");
    printf("---------------------------\n");
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
    fflush(stdin);
    scanf("%d",&command);
    return command;
}

void invalidCommand(){
    printf("---------------------------\n");
    printf("     INVALID COMMAND!! \n");
    printf("---------------------------\n\n");
    delay(2);
}

void addNewDisplay(){
    printf("---------------------------\n");
    printf("      Add New Contact \n");
    printf("---------------------------\n\n");
}

int contactOptions(){
    printf("    0 - HOME\n");
    printf("    1 - EDIT CONTACT\n");
    printf("    2 - DELETE CONTACT\n\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("        ENTER OPTION  [0-2] \n");
    printf("---------------------------------------------------------------------------------\n");
    int command;
    fflush(stdin);
    scanf("%d",&command);
    return command;
}

int editOptions(){
    printf("---------------------------------------------------------------------------------\n");
    printf("        EDIT CONTACT \n");
    printf("---------------------------------------------------------------------------------\n");
    printf("    0 - GO BACK TO HOME\n");
    printf("    1 - EDIT NAME\n");
    printf("    2 - EDIT NUMBER\n");
    printf("    3 - EDIT ADDRESS\n");
    printf("    4 - EDIT EMAIL\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("        ENTER OPTION  [0-4] \n");
    printf("---------------------------------------------------------------------------------\n");
    int command;
    fflush(stdin);
    scanf("%d",&command);
    return command;
}