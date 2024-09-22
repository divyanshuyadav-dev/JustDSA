#include <stdio.h>

// Global Variable
#define max 5
int stack[max];
int tos = -1;

// Is Empty?
int isEmpty()
{
    if (tos == -1)
        // True
        return 1;
    // False
    return 0;
}

// Is Full?
int isFull()
{
    if (tos == max - 1)
        // True
        return 1;
    // False
    return 0;
}

// Push
void push()
{
    if (isFull())
        printf("\n!!!!! Stack Overflow !!!!!\n");
    else
    {
        int data;
        printf("Enter The Value to Push: ");
        scanf("%i", &data);
        stack[++tos] = data;
    }
}

// Pop
int pop()
{
    int data = -1;
    if (isEmpty())
        printf("\n!!!!! Stack Underflow !!!!!\n");
    else
        data = stack[tos--];
    return data;
}

// Peek
int peek()
{
    if (isEmpty())
        // Nothing To Peek Here, Mister
        printf("\n!!!!! Stack is Empty !!!!!\n");
    else
        return stack[tos];
    return -1;
}

// Display
void display()
{
    if (isEmpty())
        printf("\n!!!!! Stack is Empty !!!!!\n");
    else
        for (int i = tos; i >= 0; i--)
            printf("%i\n", stack[i]);
}

int main()
{
    int opNo, data;
    printf("\n----- Stack by using Array -----\n");

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
                push();
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
