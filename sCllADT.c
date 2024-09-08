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
    scNode* ptr = head;
    for(int i = 1; i <= len; i++, ptr = ptr -> next)
        printf("Node %i: %i\n", i, ptr -> data);
}

// Creating Singly Circular Linked List
void createSCll()
{
    printf("\n----- Creating Singly Circular Linked List -----\n");
    int run = 1;
    while (run)
    {
        // Creating A New Node
        scNode* newNode = getScNode();

        // Getting Data for New Node from The User
        printf("\nEnter the Data in New Node: ");
        scanf("%i", &(newNode -> data));

        // Connecting newNode with our Singly Circular Linked List
        if (len == 0)
            // Connecting First Node in Singly Circular Linked List
            head = tail = newNode -> next = newNode;
        else
        {
            // Connecting Rest of the Node in Singly Circular Linked List
            tail -> next = newNode;
            newNode -> next = head;
            tail = newNode;
        }

        // Incrementing The Length
        len++;
        traverse();

        // More Nodes?
        printf("\nWould you like to create another Node? (0/1)\n=> ");
        scanf("%i", &run);
    }
}

int main()
{
    createSCll();
    return 0;
}