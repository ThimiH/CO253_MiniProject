/*
Contact data mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInterface.h"

#define NAME_SIZE 100
#define NUMBER_SIZE 15
#define ADDRESS_SIZE 300
#define EMAIL_SIZE 40

typedef struct contact{
    char name[NAME_SIZE];
    char number[NUMBER_SIZE];
    char address[ADDRESS_SIZE];
    char email[EMAIL_SIZE];
    struct contact *next;
} contact;

typedef struct contactList{
    int index;
    contact *ptr;
} contactList;

void deleteContact(contact * prev);
void editContact(contact * prev);

contact *head_contact = NULL, *current_contact = NULL;
int contact_count = 0;

void loadContactsFromCSV(){
    head_contact = NULL;
    FILE *fptr = fopen("Contacts.csv","r");
    if (fptr==NULL){
        fptr = fopen("Contacts.csv","w");
        fprintf(fptr, "NAME,PHONE_NUMBER,ADDRESS,EMAIL_ADDRESS\n");
        fclose(fptr);
        fptr = fopen("Contacts.txt","r");
    }
    contact cont, *node;
    while (fscanf(fptr, "%[^,],%[^,],%[^,],%s\n", cont.name,cont.number,cont.address,cont.email)>0){
        node = (contact*) malloc(sizeof(contact));
        strcpy(node->name,cont.name);
        strcpy(node->number,cont.number);
        strcpy(node->address,cont.address);
        strcpy(node->email,cont.email);
        node->next = NULL;

        if (head_contact==NULL){
            current_contact = head_contact = node;
        }
        else{
            contact_count++;
            current_contact = current_contact->next = node;
        }   
    }
    fclose(fptr);

}

void saveContactsToCSV(){
    FILE *fptr = fopen("Contacts.csv","w");
    contact *node = head_contact;
    while (node!=NULL){
        printf("%s,%s,%s,%s\n", node->name,node->number,node->address,node->email);
        fprintf(fptr, "%s,%s,%s,%s\n", node->name,node->number,node->address,node->email);
        current_contact = node->next;
        free(node);
        node = current_contact;
    }
}

void addNewContact(){
    addNewDisplay();
    contact *newContact;
    newContact = (contact*) malloc(sizeof(contact));

    printf("-> Enter the Name \n-> ");
    fflush(stdin);
    scanf("%[^\n]%*c",newContact->name);
    printf("-> Enter the Phone Number \n-> ");
    fflush(stdin);
    scanf("%[^\n]s",newContact->number);
    printf("-> Enter the Address ( Without Commas (,) ) \n-> ");
    fflush(stdin);
    scanf("%[^\n]s",newContact->address);
    printf("-> Enter the e-mail address \n-> ");
    fflush(stdin);
    scanf("%[^\n]s",newContact->email);
    newContact->next = NULL;
    
    current_contact = head_contact;
    while (current_contact->next!=NULL){
        if(strcmp(current_contact->next->name,newContact->name)>0){
            newContact->next=current_contact->next;
            current_contact->next=newContact;
            break;
        }
        current_contact = current_contact->next;
    }
    if(newContact->next==NULL){
        current_contact->next=newContact;
    }
    contact_count++;
    printf("\nContact saved successfully! \n\n");
    delay(2);
}

void displayContact(contact * prev){
    contact * node = prev->next;
    system("cls");
    printf("---------------------------------------------------------------------------------\n",node->name);
    printf("                                 CONTACT DETAILS\n",node->name);
    printf("---------------------------------------------------------------------------------\n\n",node->name);
    printf("  NAME    -> %s\n",node->name);
    printf("  NUMBER  -> %s\n",node->number);
    printf("  ADDRESS -> %s\n",node->address);
    printf("  EMAIL   -> %s\n\n",node->email);

    switch(contactOptions()){
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

void deleteContact(contact * prev){
    contact * node = prev->next;
    prev->next = node->next;
    free(node);
    printf("Contact Deleted!/n");
    contact_count--;
    delay(2);
}

void editContact(contact * prev){
    contact *node = prev->next;
    switch(editOptions()){
        case 0:
            break;
        case 1:
            printf("\n -> Enter the new name \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->name);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        case 2:
            printf("\n -> Enter the new number \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->number);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        case 3:
            printf("\n -> Enter the new address \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->address);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        case 4:
            printf("\n -> Enter the new e-mail \n -> ");
            fflush(stdin);
            scanf("%[^\n]%*c",node->email);
            printf(" -> Succsessfully changed \n -> ");
            delay(2);
            break;
        default:
            invalidCommand();
    }
}

void searchByName(){
    contact *node;
    current_contact = head_contact;
    contactList contList[contact_count]; 
    int ind = 1;

    char searchName[NAME_SIZE];
    system("cls");
    printf("\n---------------------------\n");
    printf("Enter the name below\n");
    printf("---------------------------\n\n -> ");
    fflush(stdin);
    scanf("%[^\n]s",searchName);

    while(current_contact->next->next!=NULL){
        node = current_contact->next;
        if(strstr(node->name,searchName)!=NULL){
            contList[ind-1].index = ind++;
            contList[ind-2].ptr = current_contact;
        }
        current_contact = node;
    }
    printf("%d contact(/s) found!\n\n",ind-1);
    for (int i=0; i<ind-1;i++){
        printf("%d - %s\n",contList[i].index,contList[i].ptr->next->name);
    }
    printf("\n ");
    printf("---------------------------\n");
    printf("ENTER OPTION  [0-%d] \n",ind-1);
    printf(" 0 to go home. \n Other to view contact.\n");
    printf("---------------------------\n");
    fflush(stdin);
    int command;
    scanf("%d",&command);
    if (command==0){
    }
    else if(1<=command<ind){
        displayContact(contList[command-1].ptr);
    }
    else{
        invalidCommand();
    }

}

void searchByNumber(){
    contact *node;
    current_contact = head_contact;
    contactList contList[contact_count]; 
    int ind = 1;

    char searchNumber[NUMBER_SIZE];
    system("cls");
    printf("\n---------------------------\n");
    printf("Enter the number below\n");
    printf("---------------------------\n\n -> ");
    fflush(stdin);
    scanf("%[^\n]s",searchNumber);

    while(current_contact->next->next!=NULL){
        node = current_contact->next;
        if(strstr(node->number,searchNumber)!=NULL){
            contList[ind-1].index = ind++;
            contList[ind-2].ptr = current_contact;
        }
        current_contact = node;
    }
    printf("%d contact(/s) found!\n\n",ind-1);
    for (int i=0; i<ind-1;i++){
        printf("%d - %s\n",contList[i].index,contList[i].ptr->next->name);
    }
    printf("\n ");
    printf("---------------------------\n");
    printf("ENTER OPTION  [0-%d] \n",ind-1);
    printf(" 0 to go home. \n Other to view contact.\n");
    printf("---------------------------\n");
    fflush(stdin);
    int command;
    scanf("%d",&command);
    if (command==0){
    }
    else if(1<=command<ind){
        displayContact(contList[command-1].ptr);
    }
    else{
        invalidCommand();
    }

}

void listDownContacts(){
    current_contact = head_contact;
    contactList contList[contact_count]; 
    int ind = 1;
    for (int i=0; i<contact_count; i++){
        contList[i].index=i+1;
        contList[i].ptr = current_contact;
        printf("%d - %s\n",contList[i].index,contList[i].ptr->next->name);
    }
    printf("\n ");
    printf("---------------------------\n");
    printf(" ENTER OPTION  [0-%d] \n",contact_count);
    printf(" -> 0 to go home. \n -> Other to view contact.\n");
    printf("---------------------------\n");
    fflush(stdin);
    int command;
    scanf("%d",&command);
    if (command==0){
    }
    else if(1<=command<ind){
        displayContact(contList[command-1].ptr);
    }
    else{
        invalidCommand();
    }
}
