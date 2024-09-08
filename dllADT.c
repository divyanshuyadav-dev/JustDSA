#include <stdio.h>
#include <stdlib.h>

// BluePrint of Single Linked List Node
typedef struct dllNode
{
    int data;
    struct dllNode* prev;
    struct dllNode* next;
} node;

// Global Variables
node* head, *tail;
int len;

// Insertion at The Beginning
void insertBeginning()
{
    // Creation of New Node
    node* newNode = (node*) malloc(sizeof(node));

    // Set Prev to NULL because It's First Node
    newNode->prev = NULL;

    // Connecting With Next Node if Any
    newNode->next = head;

    // Connecting First Node's Prev to New Node
    if (head != NULL)
    {
        head->prev = newNode;
    }

    // Changing Head's Aim
    head = newNode;
    
    // Connecting Tail with newNode
    // if newNode is also the Last Node in the Linked List
    if (tail == NULL)
    {
        tail = newNode;
    }

    printf("Enter the Data for New Node: ");
    scanf("%i", &(newNode->data));
    head = newNode;
    len++;
}

// Insertion at The End
void insertEnd()
{

    len++;
}

// Insertion at a Specific Location
void insertLoc()
{

    len++;
}

// Deletion at The Beginning
int deleteBeginning()
{

    len--;
    return -1;
}

// Deletion at The End
int deleteEnd()
{

    len--;
    return -1;
}

// Deletion at a Specific Location
int deleteLoc()
{

    len--;
    return -1;
}

// Traverse
void traverse()
{
    if (len == 0)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        node* ptr = head;
        for (int i = 1; i <= len; i++, ptr = ptr->next)
        {
            printf("Node %i: %i\n", i, ptr->data);
        }
    }
}

int main() 
{
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