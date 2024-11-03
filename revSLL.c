#include <stdio.h>
#include <stdlib.h>

// BluePrint of Single Linked List Node
typedef struct sllNode
{
    int data;
    struct sllNode* next;
} SLLnode;

// Global Variable
SLLnode* head;
int len;

// Traverse
void traverse()
{
    printf("\n----- Traverse -----\n");
    SLLnode* ptr = head;
    for (int i = 1; i <= len; i++, ptr = ptr -> next)
        printf("Node %i: %i\n", i, ptr -> data);
}

// Create New Node and return It's Address
SLLnode* getSllNode()
{
    return (SLLnode*) malloc(sizeof(SLLnode));
}

// Create Single Linked List
void createSLL(int n)
{
    SLLnode* tempTail;
    for (int i = 0; i < n; i++)
    {
        // Creating A New Node
        SLLnode* newNode = getSllNode();

        // Getting Data for New Node from The User
        printf("Enter the Data for New Node: ");
        scanf("%i", &(newNode -> data));

        // New Node is also the last node of the list
        // So, it point to No one
        newNode -> next = NULL;

        // Connecting newNode with our Single Linked List
        if (len == 0)
            // Connecting First Node in Single Linked List
            head = tempTail = newNode;
        else
        {
            // Connecting Rest of the Node in Single Linked List
            tempTail -> next = newNode;
            tempTail = newNode;
        }
        len++;
    }
    traverse();
}

// Reverse Single Linked List
SLLnode* reverseSLL()
{
    SLLnode* prev = NULL, *current = head, *next;

    while (current != NULL) {
        // Store next
        next = current -> next;

        // Points To The Opposite Side
        current -> next = prev;

        // Shifting The SLLnode Pointers
        prev = current;
        current = next;
    }

    head = prev;
    printf("\n----- Single Linked List Reversed -----\n");
}

int main()
{
    // Getting Size of node from the User
    int size;
    printf("How many nodes you want in Single Linked List?\n=> ");
    scanf("%i", &size);

    // Creating Single Linked List
    createSLL(size);

    // Reverse Single Linked List
    reverseSLL();
    traverse();
    return 0;
}
