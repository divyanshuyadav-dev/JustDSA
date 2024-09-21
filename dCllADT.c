#include <stdio.h>
#include <stdlib.h>

// BluePrint of Doubly Circular Linked List Node
typedef struct dCllNode
{
    int data;
    struct dCllNode* prev;
    struct dCllNode* next;
} dcNode;

// Global
dcNode* head, *tail;
int len;

// Create New Node and Return It's Address
dcNode* getDcNode()
{
    return malloc(sizeof(dcNode));
}

// Traverse
void traverse()
{
    printf("\n-----Traverse-----\n");
    if (len == 0)
        printf("\n!!!!! Doubly Circular Linked List is Empty !!!!!\n");
    else
    {
        int i = 1;
        dcNode* ptr = head;
        for(int i = 1; i <= len; i++, ptr = ptr -> next)
            printf("Node %i: %i\n", i, ptr -> data);
    }   
}

// Insertion at The Beginning
void insertBeginning()
{
    // newNode Creation
    dcNode* newNode = getDcNode();

    // newNode Data
    printf("Insert Data: ");
    scanf("%i", &(newNode -> data));

    // newNode Next
    if (len == 0)
    {
        // If It's The Only Node in The Doubly Circular Linked List
        newNode -> next = newNode;
        newNode -> prev = newNode;

        // Setting up Tail Pointer
        tail = newNode;
    }
    else
    {
        // If It's Not The Only Node in The Doubly Circular Linked List

        // Connecting New First Node With Prev First Node
        newNode -> next = head;
        head -> prev = newNode;

        // Connecting Last Node With First Node
        newNode -> prev = tail;
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
        dcNode* newNode = getDcNode();

        // newNode Data
        printf("Insert Data: ");
        scanf("%i", &(newNode -> data));

        // Connecting New Last Node With First Node
        newNode -> next = head;
        head -> prev = newNode;

        // Connecting New Node With Prev Last Node
        tail -> next = newNode;
        newNode -> prev = tail;

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
        dcNode* ptr = head;
        for (int i = 1; i < loc; i++, ptr = ptr -> next);

        // Creating newNode
        dcNode* newNode = getDcNode();

        // Node Data
        printf("Insert Data: ");
        scanf("%i", &(newNode -> data));

        // Connecting New Node With Prev Node
        newNode -> prev = ptr -> prev;
        (ptr -> prev) -> next = newNode;

        // Connecting New Node With Next Node
        newNode -> next = ptr;
        ptr -> prev = newNode;

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
        printf("Doubly Circular Linked List is Empty\n");
    else
    {
        // Fetching Data of The Node That Will Be Deleted
        int tempData = head -> data;

        if (len == 1)
        {
            // If There is Just One Node in Doubly Circular Linked List
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            // If There is More Than One Node in Doubly Circular Linked List
            dcNode* tempNext = head -> next;
            free(head);
            head = tempNext;

            // Connecting New Head with Tail
            head -> prev = tail;
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
    if (head == NULL)
        printf("Doubly Circular Linked List is Empty\n");
    else if (len == 1)
        return deleteBeginning();
    else
    {
        // Fetching Data of The Node That Will Be Deleted
        int lastData = tail -> data;

        // Deleteing Last Node From Doubly Circular Linked List    
        dcNode* tempPrev = tail -> prev;
        free(tail);

        // Setting up Tail Pointer
        tail = tempPrev;

        // Connecting New Last Node With Head
        tail -> next = head;
        head -> prev = tail;

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
            dcNode* ptr = head;
            for (int i = 1; i < loc; i++, ptr = ptr -> next);

            // Fetching Data of The Node That Will Be Deleted
            tempData = ptr -> data;

            // Connecting Surrounding Nodes To Each Other
            (ptr -> next) -> prev = ptr -> prev;
            (ptr -> prev) -> next = ptr -> next;

            // Deleteing Node From Doubly Circular Linked List    
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
    printf("\n----- Doubly Circular Linked List -----\n");
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
                printf("\n-----Deleting at The Beginning-----\n");
                data = deleteBeginning();
                if (data == -1)
                {
                    printf("\n!!!!! Error !!!!!\n");
                    break;
                }
                printf("\n%i has been Deleted\n", data);
                break;
            case 4:
                printf("\n-----Deleting at The Beginning-----\n");
                data = deleteBeginning(); 
                if (data == -1)
                {
                    printf("\n!!!!! Error !!!!!\n");
                    break;
                }
                printf("\n%i has been Deleted\n", data);
                break;
            case 5:
                printf("\n-----Deleting at The End-----\n");
                data = deleteEnd();
                if (data == -1)
                {
                    printf("\n!!!!! Error !!!!!\n");
                    break;
                }
                printf("\n%i has been Deleted\n", data);
                break;
            case 6:
                printf("\n-----Deleting at a Specific Location-----\n");
                data = deleteLoc();
                if (data == -1)
                {
                    printf("\n!!!!! Error !!!!!\n");
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