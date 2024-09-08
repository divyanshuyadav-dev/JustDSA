#include <stdio.h>
#include <stdlib.h>

// BluePrint of Double Linked List Node
typedef struct dllNode
{
    int data;
    struct dllNode* prev;
    struct dllNode* next;
} dNode;

// Globle
dNode* head, *tail;
int len;

// Create New Node and Return It's Address
dNode* getDNode()
{
    dNode* newNode = (dNode*) malloc(sizeof(dNode));
    return newNode;
}

// Create Double Linked List Initially
void createDoubleLinkedList()
{
    int run = 1;
    while (run)
    {
        if (len == 0)
        {
            // This Will Run While Creating The Very First Node
            printf("\n-----Creating The Very First Node-----\n");
            dNode* a = getDNode();
            printf("Enter the Value: ");
            scanf("%i", &(a -> data));
            head = a;
            tail = a;
            a -> prev = NULL;
            a -> next = NULL;
            len++;
            printf("First Node is Created\n");
        }
        else
        {
            // This will Run for All Nodes But Not For The First
            printf("\n-----Creating Another Node-----\n");
            dNode *a = getDNode();
            printf("Enter the Value: ");
            scanf("%i", &(a -> data));
            a -> prev= tail;
            tail -> next = a;
            tail = a;
            len++;
            printf("A New Node is Created\n");
        }
        printf("Would you like to create another Node (0/1): ");
        scanf("%i", &run);
    }
}

// Traverse
void traverse()
{
    printf("\n-----Traverse-----\n");
    dNode* ptr = head;
    if (len == 0)
        printf("\n!!!!! Double Linked List is Empty !!!!!\n");
    else
        for(int i = 1; i <= len; i++, ptr = ptr -> next)
            printf("Node %i: %i\n", i, ptr -> data);
}

// Inserting at Beginning
void insertBeginning()
{
    dNode* a = getDNode();
    a -> prev = NULL;
    a -> next = head;

    if (len == 0)
        // Linked List is Empty
        tail = a;
    else
        // Linked List isn't Empty
        head -> prev = a;

    // New Node has been Declared as The First Node
    head = a;
    printf("Enter The Value For New Node: ");
    scanf("%i", &(a -> data));
    len++;
    traverse();
}

// Inserting at End
void insertEnd()
{
    dNode* a = getDNode();
    a -> prev = tail;
    a -> next = NULL;

    if (len == 0)
        // Linked List is Empty
        head = a;
    else
        // Linked List isn't Empty
        tail -> next = a;

    // New Node has been Declared as The Last Node
    tail = a;
    printf("Enter The Value For New Node: ");
    scanf("%i", &(a -> data));
    len++;
    traverse();
}

// Insertion at Specific Location
void insertLoc()
{
    int pos, error;
    do
    {
        error = 0;
        printf("\nAt Which Location you want to Insert?\n=> ");
        scanf("%i", &pos);
        if(pos > len || pos <= 1)
        {
            printf("Invalid Input\n");
            error = 1;
        }
    }
    while (error);

    dNode* a = getDNode();
    dNode* ptr = head;

    // Fetching The Node Before We Have To Insert New Node
    for (int i = 1; i != pos; i++, ptr = ptr -> next);

    // Insertion
    a -> prev = ptr -> prev;
    (a -> prev) -> next = a;
    a -> next = ptr;
    (a -> next) -> prev = a;

    printf("Enter The Value For New Node: ");
    scanf("%i", &(a -> data));

    len++;
    traverse();
}

// Deletion at Beginning
int deleteBeginning()
{
    // If Double Linked List is Empty
    if (len == 0)
        printf("\n!!!!! Double Linked List is Empty !!!!!\n");
    else
    {
        // If Double Linked List isn't Empty
        int data;

        if (len == 1)
        {
            // If There is only a Single Node in Double Linked List
            data = head -> data;
            free(head);
            head = NULL;
            tail = NULL;
        }
        else if (len > 1)
        {
            // If There is Multiple Nodes in Double Linked List
            data = head -> data;
            head = head -> next;
            free(head -> prev);
            head -> prev = NULL;
        }
        len--;
        traverse();
        return data;
    }
    return -1;
}

// Deletion at End
int deleteEnd()
{
    // If Double Linked List is Empty
    if (len == 0)
        printf("\n!!!!! Double Linked List is Empty !!!!!\n");
    else
    {
        // If Double Linked List isn't Empty
        int data;

        if (len == 1)
        {
            // If There is only a Single Node in Double Linked List
            data = tail -> data;
            free(tail);
            tail = NULL;
            head = NULL;
        }
        else if (len > 1)
        {
            // If There is Multiple Nodes in Double Linked List
            data = tail -> data;
            tail = tail -> prev;
            free(tail -> next);
            tail -> next = NULL;
        }
        len--;
        traverse();
        return data;
    }
    return -1;
}

// Deletion at Specific Location
int deleteLoc()
{
    int pos, error;
    if (len == 0)
        printf("\n!!!!! Double Linked List is Empty !!!!!\n");
    else
    {
        do
        {
            error = 0;
            printf("\nAt Which Location you want to Delete?\n=> ");
            scanf("%i", &pos);
            if (pos > len || pos < 1)
            {
                printf("Invalid Input\n");
                error = 1;
            }
        }
        while (error);

        dNode* ptr = head;
        if (pos == 1)
            // Deletion at First Postion
            return deleteBeginning();
        else if (pos == len)
            // Deletion at Last Postion
            return deleteEnd();
        else
        {
            // Fetching The Postion Which We Want To Delete
            for (int i = 1; i != pos; i++, ptr = ptr -> next);

            // Deletion
            int data = ptr -> data;
            (ptr -> prev) -> next = ptr -> next;
            (ptr -> next) -> prev = ptr -> prev;
            free(ptr);
            ptr = NULL;

            len--;
            traverse();
            return data;
        }
    }
    return -1;
}

int main()
{
    // Create Double Linked List Initially
    createDoubleLinkedList();
    traverse();

    // Menu Driven operations for Double Linked List
    int opNo, run = 1, data;
    while (run)
    {
        printf("\n1. Insertion at Beginning\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion at Specific Location\n");
        printf("4. Deletion at Beginning\n");
        printf("5. Deletion at End\n");
        printf("6. Deletion at Specific Location\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%i", &opNo);
        switch (opNo)
        {
            case 1:
                printf("\n-----Inserting at Beginning-----\n");
                insertBeginning();
                break;
            case 2:
                printf("\n-----Inserting at End-----\n");
                insertEnd();
                break;
            case 3:
                printf("\n-----Inserting at Specific Location-----\n");
                insertLoc();
                break;
            case 4:
                printf("\n-----Deleting at Beginning-----\n");
                data = deleteBeginning();
                if (data == -1)
                    printf("\n!!!!! Error !!!!!\n");
                else
                    printf("\n%i has been Deleted\n", data);
                break;
            case 5:
                printf("\n-----Deleting at End-----\n");
                data = deleteEnd();
                if (data == -1)
                    printf("\n!!!!! Error !!!!!\n");
                else
                    printf("\n%i has been Deleted\n", data);
                break;
            case 6:
                printf("\n-----Deleting at Specific Location-----\n");
                data = deleteLoc();
                if (data == -1)
                    printf("\n!!!!! Error !!!!!\n");
                else
                    printf("\n%i has been Deleted\n", data);
                break;
            case 7:
                traverse();
                break;
            case 8:
                return 0;
        }
    }
    return 1;
}
