#include <stdio.h>
#include <stdlib.h>

// BluePrint of Single Linked List Node
typedef struct sllNode
{
    int data;
    struct sllNode* next;
} node;

// Global Variables
node* head = NULL, *newNode;
int len = 0;

// Create Single Linked List Node and Returns It's Address
node* getSLLnode()
{
    return (node*) malloc(sizeof(node));
}

// Insertion at The Beginning
void insertBeginning()
{
    // newNode Creation
    newNode = getSLLnode();
    
    // Node Data 
    printf("Insert Data: ");
    scanf("%i", &(newNode -> data));

    // Node Next
    newNode -> next = head;

    // Connecting With Prev Node
    head = newNode;

    // Manipulating Length of Linked List
    len++;
}

// Insertion at The End
void insertEnd()
{
    if (head == NULL)
        insertBeginning();
    else
    {
        // Traversing To The End of The Linked List
        node* ptr = head;
        while (ptr -> next != NULL)
            ptr = ptr -> next;

        // Creating New Node To Append
        newNode = getSLLnode();

        // Node Data
        printf("Insert Data: ");
        scanf("%i", &(newNode -> data));

        // Node Next
        newNode -> next = NULL;

        // Connecting With Prev Node
        ptr -> next = newNode;

        // Manipulating Length of Linked List
        len++;
    }
}

// Insertion at a Specific Location
void insertLoc()
{
    int loc, error;
    node* ptr = head, *prev;
    do
    {
        printf("Enter The Location: ");
        scanf("%i", &loc);

        error = 0;
        if (loc > len + 1 || loc < 1)
        {
            printf("!!!!! Invalid Input !!!!!\n");
            error = 1;
        }
    }
    while (error);
    
    if (loc == 1)
        insertBeginning();
    else
    {
        for (int i = 1; i < loc; i++, ptr = ptr -> next)
            prev = ptr;
        
        // Creating newNode
        newNode = getSLLnode();

        // Node Data
        printf("Insert Data: ");
        scanf("%i", &(newNode -> data));

        // Node Next
        newNode -> next = ptr;

        // Connecting With Prev Node
        prev -> next = newNode;

        // Manipulating Length of Linked List
        len++;
    }
}

// Deletion at The Beginning
int deleteBeginning()
{
    if (head == NULL)
        printf("Linked List is Empty\n");
    else
    {
        node* tempNext = head -> next;
        int tempData = head -> data;
        free(head);
        head = tempNext;
        len--;
        return tempData;
    }
    return -1;
}

// Deletion at The End
int deleteEnd()
{
    if (head == NULL)
        printf("Linked List is Empty\n");
    else if (len == 1)
        return deleteBeginning();
    else
    {
        node* ptr = head, *prev;
        while (ptr -> next != NULL)
        {
            prev = ptr;
            ptr = ptr -> next;
        }
        int lastData = ptr -> data;
        free(ptr);
        ptr = NULL;
        prev -> next = NULL;
        len--;
        return lastData;
    }
    return -1;
}

// Deletion at a Specific Location
int deleteLoc()
{
    if (head == NULL)
        printf("Linked List is Empty\n");
    else
    {
        int loc, error, tempData;
        node* ptr = head, *prev;
        do
        {
            printf("Enter The Location: ");
            scanf("%i", &loc);

            error = 0;
            if (loc < 1 || loc > len)
            {
                printf("!!!!! Invalid Input !!!!!\n");
                error = 1;
            }
        } 
        while (error);

        if (loc == 1)
            return deleteBeginning();
        else
        {
            for (int i = 1; i < loc; i++, ptr = ptr -> next)
                prev = ptr;
            
            tempData = ptr -> data;
            prev -> next = ptr -> next;
            free(ptr);
            ptr = NULL;
            len--;
            return tempData;
        }
    }
    return -1;
}

// Traverse
void traverse()
{
    if (head == NULL)
        printf("Linked List is Empty\n");
    else
    {
        node* ptr = head;
        for (int i = 1; i <= len; i++, ptr = ptr -> next)
        {
            printf("Node %i: %i\n", i, ptr -> data);
        }
    }
}

int main() 
{
    printf("\n----- Single Linked List -----\n");
    int opNo, data;
    while (1)
    {
        printf("\n1. Insertion at The Beginning\n");
        printf("2. Insertion at The End\n");
        printf("3. Insertion at a Specific Location\n");
        printf("4. Deletion at The Beginning\n");
        printf("5. Deletion at The End\n");
        printf("6. Deletion at a Specific Location\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter The Operation Number: ");
        scanf("%i", &opNo);
        switch (opNo)
        {
            case 1:
                printf("\n-----Inserting at The Beginning-----\n");
                insertBeginning();
                break;
            case 2:
                printf("\n-----Inserting at The End-----\n");
                insertEnd();
                break;
            case 3:
                printf("\n-----Inserting at a Specific Location-----\n");
                insertLoc();
                break;
            case 4:
                printf("\n-----Deleting at The Beginning-----\n");
                data = deleteBeginning();
                if (data == -1)
                {
                    printf("!!!!! Error !!!!!");
                    return -1;
                }
                printf("%i has been Deleted\n", data);
                break;
            case 5:
                printf("\n-----Deleting at The End-----\n");
                data = deleteEnd();
                if (data == -1)
                {
                    printf("!!!!! Error !!!!!");
                    return -1;
                }
                printf("%i has been Deleted\n", data);
                break;
            case 6:
                printf("\n-----Deleting at a Specific Location-----\n");
                data = deleteLoc();
                if (data == -1)
                {
                    printf("!!!!! Error !!!!!");
                    return -1;
                }
                printf("%i has been Deleted\n", data);
                break;
            case 7:
                printf("\n-----Traverse-----\n");
                traverse();
                break;
            case 8:
                return 0;
            default:
                printf("\n!!!!! Invalid Input !!!!!\n");
                break;
        }
    }
    return 1;
}