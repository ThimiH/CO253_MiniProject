/*
UI of the contact mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

#include <stdio.h>

int homeMenu(){
    printf("---------------------------\n");
    printf(" CONTACT MANAGEMENT SYSTEM \n");
    printf("---------------------------\n\n");
    printf("---------------------------\n");
    printf("---------------------------\n");
    printf("---------------------------\n");
    printf("---------------------------\n");
    printf("---------------------------\n");
    printf("---------------------------\n\n");
    printf("--------------------\n");
    printf(" ENTER OPTION [0-5] \n");
    printf("--------------------\n");
    int command;
    scanf("%d",&command);
    return command;
}

int searchForContacts(){
    printf("---------------------\n");
    printf(" SEARCH FOR CONTACTS \n");
    printf("---------------------\n\n");
    printf("0 - SEARCH BY NAME\n");
    printf("1 - SEARCH BY NUMBER\n");
    printf("2 - BACK\n\n");
    printf("--------------------\n");
    printf(" ENTER OPTION [0-2] \n");
    printf("--------------------\n");
    int command;
    scanf("%d",&command);
    return command;
}

void invalidCommand(){
    printf("------------------\n");
    printf(" INVALID COMMAND! \n");
    printf("------------------\n\n");
}