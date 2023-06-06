/*
Main programme of the contact mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

// Include required header files
#include <stdio.h>
#include <stdlib.h>
#include "contactManagement.h"

//Main function handles the basic logic.
int main() {
    loadContactsFromCSV();                      //Initially contacts are loaded from the data base

    while (1){                                  //Main loop runs until the quit command is given
        switch (homeMenu()){                    //Switch between functions using the input to the home menu
            case 0:
                saveContactsToCSV();
                return 0;
            case 1:
                system("cls");
                addNewContact();
                break;
            case 2:
                listDownContacts();
                break;
            case 3:                             //This has sub cases of search by name and number
                switch (searchForContacts(contact_count)){
                    case 0:
                        searchByName();
                        break;
                    case 1:
                        searchByNumber();
                        break;
                    case 2:
                        break;
                    default:
                        invalidCommand();
                }
                break;
            default:
                system("cls");
                invalidCommand();               //If the command is invalid, this function is called
        }
    }
    return 0;
}
