/*
Main programme of the contact mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

#include <stdio.h>
#include "userInterface.h"
#include "contactManagement.h"


int main() {
    while (1){
        switch (homeMenu()){
            case 0:
                return 0;            
            case 1:
                break;            
            case 2:
                break;            
            case 3:
                break;            
            case 4:
                break;
            case 5:
                break;
            default:
                invalidCommand();
        }
    }
    return 0;
}