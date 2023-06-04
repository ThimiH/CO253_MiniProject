/*
Contact data mangement system.
Date:21/05/2023
Author: Thimira Hirushan (E/19/276)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    contact *prt;
} contactList;

contact *head_contact = NULL, *current_contact = NULL;

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
    contact *newContact;
    newContact = (contact*) malloc(sizeof(contact));

    printf("-> Enter the Name \n-> ");
    scanf("%s\n",newContact->name);
    printf("-> Enter the Phone Number \n-> ");
    scanf("%s\n",newContact->number);
    printf("-> Enter the Address ( Without Commas (,) ) \n-> ");
    scanf("%s\n",newContact->address);
    printf("-> Enter the e-mail address \n-> ");
    scanf("%s\n",newContact->email);
    newContact->next = NULL;
    
    current_contact = head_contact;
    while (current_contact->next!=NULL){
        if(strcmp(current_contact->next->name,newContact->name)>0){
            newContact->next=current_contact->next;
            current_contact->next=newContact;
        }
        current_contact = current_contact->next;
    }
    if(newContact->next==NULL){
        current_contact->next=newContact;
    }

    printf("Contact saved successfully!");
}

void deleteContact(){

}

void searchByName(){

}

void searchByNumber(){

}

void listDownContacts(){

}

