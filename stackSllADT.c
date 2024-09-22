#include <stdio.h>
#include <stdlib.h>

// BluePrint of Stack Single Linked List Node
typedef struct stackSNode
{
    int data;
    struct stackSNode* next;
} stackNode;

// Global Variable
stackNode* tos;

stackNode* getStackNode()
{
    return (stackNode*) malloc(sizeof(stackNode));
}

// Is Empty?
int isEmpty()
{
    if (tos == NULL)
        // True
        return 1;
    // False
    return 0;
}

// Push
void push(int data)
{
    // Creating a New Node
    stackNode* newNode = getStackNode();

    // Data on Top of Stack
    newNode -> data = data;

    // Points to The Next Data Value
    newNode -> next = tos;

    // Setting up Top of Stack Pointer
    tos = newNode;
}

// Pop
int pop()
{
    int data = -1;
    if (isEmpty())
        printf("\n!!!!! Stack Underflow !!!!!\n");
    else
    {
        // Fetching The Data Before Deletion
        data = tos -> data;

        // Preserving the Address of Next Node
        stackNode* tempNext = tos -> next;

        // Popping
        free(tos);

        // Setting up Top of Stack Pointer
        tos = tempNext;
    }
    return data;
}

// Peek
int peek()
{
    if (isEmpty())
        // Nothing To Peek Here, Mister
        printf("\n!!!!! Stack is Empty !!!!!\n");
    else
        return tos -> data;
    return -1;
}

// Display
void display()
{
    if (isEmpty())
        printf("\n!!!!! Stack is Empty !!!!!\n");
    else
        for (stackNode* ptr = tos; ptr != NULL; ptr = ptr -> next)
            printf("%i\n", ptr -> data);
}

int main()
{
    int opNo, data;
    printf("\n----- Stack by using Single Linked List -----\n");

    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%i", &opNo);

        switch(opNo)
        {
            case 0:
                return 0;
            case 1:
                printf("\n----- Push -----\n");
                int p;
                printf("Enter The Data to Push: ");
                scanf("%i", &p);
                push(p);
                break;
            case 2:
                printf("\n----- Pop -----\n");
                data = pop();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i has been Poped\n", data);
                break;
            case 3:
                printf("\n----- Peek -----\n");
                data = peek();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i is at Top of the Stack\n", data);
                break;
            case 4:
                printf("\n----- Display -----\n");
                display();
                break;
            default:
                printf("\n----- Invalid Input -----\n");
        }
    }
    return 1;
}
