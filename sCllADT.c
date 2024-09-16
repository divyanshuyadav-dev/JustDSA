#include <stdio.h>
#include <stdlib.h>

// BluePrint of Singly Circular Linked List Node
typedef struct sCllNode
{
    int data;
    struct sCllNode* next;
} scNode;

// Global Variables
scNode* head, *tail;
int len;

// Create New Node and Return It's Address
scNode* getScNode()
{
    return (scNode*) malloc(sizeof(scNode));
}

// Traverse
void traverse()
{
    printf("\n-----Traverse-----\n");
    if (len == 0)
        printf("\n!!!!! Singly Circular Linked List is Empty !!!!!\n");
    else
    {
        scNode* ptr = head;
        for(int i = 1; i <= len; i++, ptr = ptr -> next)
            printf("Node %i: %i\n", i, ptr -> data);
    }
}

// Insertion at The Beginning
void insertBeginning()
{
    // newNode Creation
    scNode* newNode = getScNode();
    
    // newNode Data 
    printf("Insert Data: ");
    scanf("%i", &(newNode -> data));

    // newNode Next
    if (len == 0)
    {
        // If It's The Only Node in The Singly Circular Linked List
        newNode -> next = newNode;

        // Setting up Tail Pointer
        tail = newNode;
    }
    else
    {
        // If It's Not The Only Node in The Singly Circular Linked List
        newNode -> next = head;

        // Connecting Last Node With First Node
        tail -> next = newNode;
    }

    // Setting up Head Pointer
    head = newNode;

    // Manipulating Length of Linked List
    len++;

    // Traverse
    traverse();
}

// Insertion at The End
void insertEnd()
{
    if (len == 0)
        insertBeginning();
    else
    {
        // Creating newNode To Append
        scNode* newNode = getScNode();

        // newNode Data
        printf("Insert Data: ");
        scanf("%i", &(newNode -> data));

        // newNode Next
        // Connecting New Last Node With First Node
        newNode -> next = head;

        // Connecting newNode With Prev Last Node
        tail -> next = newNode;

        // Setting up Tail Pointer
        tail = newNode;

        // Manipulating Length of Linked List
        len++;

        // Traverse
        traverse();
    }
}

// Insertion at a Specific Location
void insertLoc()
{
    int loc, error;
    scNode* ptr = head, *prev;
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
    else if (loc == len + 1)
        insertEnd();
    else
    {
        for (int i = 1; i < loc; i++, ptr = ptr -> next)
            prev = ptr;
        
        // Creating newNode
        scNode* newNode = getScNode();

        // Node Data
        printf("Insert Data: ");
        scanf("%i", &(newNode -> data));

        // Node Next
        newNode -> next = ptr;

        // Connecting With Prev Node
        prev -> next = newNode;

        // Manipulating Length of Linked List
        len++;

        // Traverse
        traverse();
    }
}

// Deletion at The Beginning
int deleteBeginning()
{
    if (head == NULL)
        printf("Linked List is Empty\n");
    else
    {
        // Fetching Data of The Node That Will Be Deleted
        int tempData = head -> data;

        if (len == 1)
        {
            // If There is Just One Node in Singly Circular Linked List
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            // If There is More Than One Node in Singly Circular Linked List
            scNode* tempNext = head -> next;
            free(head);
            head = tempNext;
            tail -> next = head;
        }

        len--;
        traverse();
        return tempData;
    }
    return -1;
}

// Deletion at The End
int deleteEnd()
{
    printf("\nStarted\n");
    if (head == NULL)
        printf("Linked List is Empty\n");
    else if (len == 1)
        return deleteBeginning();
    else
    {
        scNode* ptr = head, *prev;
        while (ptr -> next != head)
        {
            prev = ptr;
            ptr = ptr -> next;
        }
        
        // Fetching Data of The Node That Will Be Deleted
        int lastData = ptr -> data;

        // Deleteing Last Node From Singly Circular Linked List
        free(ptr);
        ptr = NULL;

        // Connecting New Last Node With Head
        prev -> next = head;

        // Setting up Tail Pointer
        tail = prev;

        len--;
        traverse();
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
        scNode* ptr = head, *prev;
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
        if (loc == len)
            return deleteEnd();
        else
        {
            for (int i = 1; i < loc; i++, ptr = ptr -> next)
                prev = ptr;
            
            tempData = ptr -> data;
            prev -> next = ptr -> next;
            free(ptr);
            ptr = NULL;

            len--;
            traverse();
            return tempData;
        }
    }
    return -1;
}

int main()
{
    printf("\n----- Singly Circular Linked List -----\n");
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
                    break;
                }
                printf("\n%i has been Deleted\n", data);
                break;
            case 5:
                printf("\n-----Deleting at The End-----\n");
                data = deleteEnd();
                if (data == -1)
                {
                    printf("!!!!! Error !!!!!");
                    break;
                }
                printf("\n%i has been Deleted\n", data);
                break;
            case 6:
                printf("\n-----Deleting at a Specific Location-----\n");
                data = deleteLoc();
                if (data == -1)
                {
                    printf("!!!!! Error !!!!!");
                    break;
                }
                printf("\n%i has been Deleted\n", data);
                break;
            case 7:
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