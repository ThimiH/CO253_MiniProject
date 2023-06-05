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

int main() {
    homeMenu();
    return 0;
}