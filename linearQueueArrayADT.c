#include <stdio.h>

// Global Variable
#define max 7
int queue[max];
int f = -1, r = -1;

// is Full?
int isFull()
{
    if (r == max - 1)
        // True
        return 1;
    // False
    return 0;
}

// is Empty?
int isEmpty()
{
    if (f == -1 && r == -1)
        // True
        return 1;
    // False
    return 0;
}

// Enqueue
void enqueue()
{
    if (isFull())
        printf("\n!!!!! Linear Queue is Full !!!!!\n");
    else
    {
        // While Enqueue The Very First Element
        if (f == -1)
            f++;
        
        // Enqueue
        printf("Enter The Element to Enqueue: ");
        scanf("%i", &queue[++r]);
    }
}

// Dequeue
int dequeue()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
    {
        // Reset Case
        if (f == r)
        {
            int data = queue[f];
            f = r = -1;
            return data;
        }

        // Return The Very Front Element
        return queue[f++];
    }
    // Error Code
    return -1;
}

// Front or Peek
int front()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
        // Return The Front Element
        return queue[f];
    // Error Code
    return -1;
}

// Rear
int rear()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
        // Return The Rear Element
        return queue[r];
    // Error Code
    return -1;
}

// Display
int display()
{
    if (isEmpty())
        printf("\n!!!!! Linear Queue is Empty !!!!!\n");
    else
        for (int i = r; i >= f; i--)
            printf("%i\n", queue[i]);
}

int main()
{
    int opNo, data;
    printf("\n----- Linear Queue by using Array -----\n");

    while(1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%i", &opNo);

        switch(opNo)
        {
            case 0:
                return 0;
            case 1:
                printf("\n----- Enqueue -----\n");
                enqueue();
                break;
            case 2:
                printf("\n----- Dequeue -----\n");
                data = dequeue();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i has been Dequeued\n", data);
                break;
            case 3:
                printf("\n----- Front -----\n");
                data = front();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i is at Front of the Linear Queue\n", data);
                break;
            case 4:
                printf("\n----- Rear -----\n");
                data = rear();
                if (data == -1)
                    printf("\n!!!!! ERROR !!!!!\n");
                else
                    printf("%i is at Rear of the Linear Queue\n", data);
                break;
            case 5:
                printf("\n----- Display -----\n");
                display();
                break;
            default:
                printf("\n----- Invalid Input -----\n");
        }
    }
    return 1;
}