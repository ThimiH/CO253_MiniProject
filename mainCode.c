/*
Main programme of the contact mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

#include <stdio.h>
#include <stdlib.h>
#include "contactManagement.h"


int main() {
    loadContactsFromCSV();

    while (1){
        switch (homeMenu()){
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
            case 3:
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
                invalidCommand();
        }
    }
    return 0;
}
