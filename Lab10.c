#include <stdio.h>
#include <stdlib.h>

//Declaring structure to store records
typedef struct _ {
    int batch;
    int regNo;
    char firstName[20];
    char lastName[20];
    float cGPA;
    struct _* next;
} student_t;

//Declaring structure to store batch number
typedef struct std_reg{
    int batch_number;
    int reg_numberr;
} std_number;

//Declaring a global pointer
student_t *head = NULL;

//Declaring the funtions
void add();
void print_record();
void print_all_records();
void delete_record();

// Function to return the batch number and the reg number
std_number number(char str[]){
    std_number std;
    std.batch_number =0;
    std.reg_numberr = 0;
    int i, j, len=0;
    // Declaring two variables to catch the two '/'s and to store the indexes to separate the batch no and reg no
    int start=0,end=0;

    // Calculating the array length
    while (str[len]!='\0') ++len;

    // Loop to catch the first '/'
    for (i=0;i<len;++i){
        if (str[i]=='/'){
            start = i;
            break;
        }
    }
    // Loop to catch the second '/'
    for(j=i+1;j<len;++j){
        if (str[j]=='/'){
            end = j;
            break;
        }
    }
    j = 0;
    // Loop to calculate the batch number which is in between the two '/'s
    for(i=end-1;i>start;--i){
        std.batch_number = std.batch_number + (str[i]-'0')*getPow(j);
        ++j;
    }
    j = 0;
    // Loop to calculate the reg number which was entered after the second '/'.
    for(i=len-1;i>end;--i){
        std.reg_numberr = std.reg_numberr + (str[i]-'0')*getPow(j);
        ++j;
    }
    return std;
}


// Function to get the power of 10
int getPow(int x){
    if (x==0) return 1;
    else
        return 10*getPow(x-1);
}

int main(){
    int opt=1;

    //Print the options and description
    printf("--------------------------------------------\n");
    printf("A VOLATILE STUDENT RECORD MAINTENANCE SYSTEM\n");
    printf("--------------------------------------------\n");

    printf("0. Quit\n");
    printf("1. Insert a Student Record\n");
    printf("2. Print a Student Record\n");
    printf("3. Print all Student Records\n");
    printf("4. Delete a Student Record\n");

    while(opt!=0){
        //read the input and store it in opt
        printf("------------------\n");
        printf("ENTER OPTION [0-4]\n");
        printf("------------------\n");
        scanf("%d", &opt);

        //When opt=1, a new student record must be added
        if (opt==1){
            add();
        }

        //When opt=2, we must print a student record
        else if (opt==2){
            print_record();
        }

        //When opt=3, print all the available student records using a loop
        else if (opt==3){
            print_all_records();
        }

        //When opt=4, we must delete a certain student record
        else if (opt==4){
            delete_record();
        }
    }
    return 0;
}

//Function to add a new student record
void add(){
    //Declare a pointer with student_t structure
    student_t *stu_next;
    stu_next = (student_t *)malloc(sizeof(student_t));

    //Read the inputs and store them in correct variable
    printf("Enter the batch (14/15/16/17): ");
    scanf("%d", &(stu_next -> batch));
    printf("Enter the registration number: ");
    scanf("%d", &(stu_next -> regNo));
    printf("Enter the first name         : ");
    scanf("%s", (stu_next -> firstName));
    printf("Enter the last name          : ");
    scanf("%s", (stu_next -> lastName));
    printf("Enter the cumulative GPA     : ");
    scanf("%f", &(stu_next -> cGPA));

    if(head == NULL){
        stu_next -> next = NULL;
        head = stu_next;
    }
    else{
        stu_next -> next = head;
        head = stu_next;
    }
    printf("\n");
}

//Function to print a certain student record
void print_record(){
    //Declare variables to store the full registration number as 'f_reg'
    char f_reg[10];
    student_t *node;
    std_number std1;

    //Read the input
    printf("Enter the Registration Number: ");
    scanf("%s", f_reg);

    std1 = number(f_reg);

    //Declare a variable to find whether the record is present or not
    int x=0;

    // Loop to check whether the given data is in the record
    for(node=head;node != NULL;node = node -> next){
        // Comparison between equal data types which are in two different structures
        if(node ->batch == std1.batch_number && node ->regNo== std1.reg_numberr){
            //Assign x to 1 to show that the record is present
            x = 1;
            break;
        }
    }

    //If the record is not present print the output
    if (x==0){
        printf("No student with the given Registration Number!\n");
        printf("\n");
    }
    else{
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n",node ->firstName,node ->lastName,node ->batch,node ->regNo,node ->cGPA);
        printf("\n");
    }
}

//Function to print all student records
void print_all_records(){
    student_t *node;
    node = head;

    while(node != NULL){
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n", node -> firstName, node -> lastName, node -> batch, node -> regNo, node -> cGPA);
        node = node -> next;
    }
    printf("\n");
}

//Function to delete a certain record
void delete_record(){
    //Declare variables to store the full registration number as 'f_reg'
    char f_reg[10];
    student_t *node1 = head;
    student_t *node2 = head;
    std_number std1;

    //Read the input
    printf("Enter the Registration Number: ");
    scanf("%s", f_reg);

    std1 = number(f_reg);

    //Declare a variable 'x' to find whether the record is present or not
    int x=0;

    while (node1 != NULL){
        // Checking the data is available
        if ( node1 -> batch == std1.batch_number && node1 -> regNo == std1.reg_numberr){
            x = 1;
            // Checking for whether the first node is the node we have to delete
            if (node1 == node2){
                head = head -> next;
                free(node1);
            } else{
                node2 -> next = node1 -> next;
                free(node1);
            }
            printf("Delete Successful!\n\n");
            break;
        }
        node2 = node1;
        node1 = node1 -> next;
    }

    if (x==0){
        printf("No student with the given Registration Number!\n");
        printf("\n");
    }
}


//Discussion

/*
1.  int batch :- 4 bytes
    int regNo :- 4 bytes
    char firstNames[20] :- 20 bytes
    char lastName[20] :- 20 bytes
    float cGPA :- 4 bytes
    struct _* next :- 8 bytes

    Total memory in data :- 60 bytes
    Memory allocated :- 64 bytes
    Memory allocated for 5 data elements :- 320 bytes


2.  Memory is allocated during the runtime of the program.
    Memory can be freed at anytime of the program using free()


3.  First, 2 student_t type pointers were declared as node1 and node2 and initializing them to the head node of the linked list.
    Then, using a while loop the nodes of the linked list were accessed from begining to end while checking whether there is the record that matches the given registration number.
        If the record that needed to be deleted is the head node, assign the head to the next node and free the memory allocated to the previous node.
        If the record that needed to be deleted is not the head node, link the next node to the previous node and free the memory allocated to the previous node.

4.  Yes. But depends on the memory available in the computer

5.  Pros :-
        Better use of memory
        Fast insertion/ deletion time
    Cons :-
        Slower search time
        More memory needed per node as additional storage required for pointers

6.  Array based
    There's a fixed value for the number of students record. Also. in linked list to modify students records, it takes longer time than arrays.
*/
