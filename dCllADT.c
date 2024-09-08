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
    dcNode* ptr = head;
    for(int i = 1; i <= len; i++, ptr = ptr -> next)
        printf("Node %i: %i\n", i, ptr -> data);
}

// Creating Doubly Circular Linked List
void createDCll()
{
    printf("\n----- Creating Doubly Circular Linked List -----\n");
    int run = 1;

    while (run)
    {
        // // Creating A New Node
        dcNode* newNode = getDcNode();

        // Getting Data for New Node from The User
        printf("\nEnter the Data for New Node: ");
        scanf("%i", &(newNode -> data));

        // Connecting newNode with our Doubly Circular Linked List
        if (len == 0)
            // Connecting First Node in Doubly Circular Linked List
            head = tail = newNode -> next = newNode -> prev = newNode;
        else
        {
            // Connecting Rest of the Node in Doubly Circular Linked List
            tail -> next = newNode;
            newNode -> prev = tail;
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
    createDCll();
    return 0;
}