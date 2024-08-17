#include <stdio.h>
#include <stdlib.h>

#define max 10

// Array Abstract Data Type
typedef struct arrayADT
{
    int maxSize;
    int size;
    int* ptr;
} array;

// Set Meta Data of Array ADT 
void createArray(array* a, int total, int size) {
    printf("Address: %p\n", a);

    (*a).maxSize = total;
    (*a).size = size;
    (*a).ptr = (int*) malloc(total * sizeof(int));
}

// Set Value of Array ADT 
void assignValue(array* a)
{
    for (int i = 0; i < (*a).size; i++)
    {
        printf("Enter the %ith Value: ", i);
        scanf("%i", (*a).ptr + i);
    }
}

// Print Value of Array ADT 
void printArray(array* a)
{
    for (int i = 0; i < (*a).size; i++)
    {
        printf("%ith Value: %i\n", i, ((*a).ptr)[i]);
    }
}

// Print Meta Data of Array ADT
void metaData(array* a)
{
    printf("Array Abstract Data Type\n");

    printf("Max: %i\n", (*a).maxSize);
    printf("Size: %i\n", (*a).size);
    printf("Pointer: %p\n", (*a).ptr);
}

// Insertion
void insert(array* a)
{
    int error, pos, value;

    // Getting A Valid Postion
    do
    {
        error = 0;
        printf("Enter The Position: ");
        scanf("%i", &pos);
        if (pos < 1 || pos > (*a).size + 1)
        {
            error = 1;
            printf("Invalid Position\n");
        }
    }
    while (error);

    // Getting Value
    printf("Enter The Value: ");
    scanf("%i", &value);
    
    // Right Shift
    int arrPos = pos - 1;
    for (int i = (*a).size - 1; i >= arrPos; i--)
    {
        printf("i -> %i\n", i); //----------------------------------------------------------
        ((*a).ptr)[i + 1] = ((*a).ptr)[i];
    }

    // Inserting Value
    ((*a).ptr)[arrPos] = value;

    // Incrementing The Array Size
    (*a).size++;
}

// Deletion
int delete(array* a)
{
    int error, pos;

    // Getting A Valid Postion
    do
    {
        error = 0;
        printf("Enter The Position: ");
        scanf("%i", &pos);
        if (pos < 1 || pos > (*a).size)
        {
            error = 1;
            printf("Invalid Position\n");
        }
    }
    while (error);

    // Fetching The Number From The Specified Position 
    int num = ((*a).ptr)[pos - 1];

    // Left Shift
    for (int i = pos; i < (*a).size; i++)
    {
        printf("i -> %i\n", i); //----------------------------------------------------------
        ((*a).ptr)[i - 1] = ((*a).ptr)[i];
    }

    // Decrementing The Array Size
    (*a).size--;

    // Return The Deleted Value
    return num;
}

// Main
int main()
{
    int size = 5;
    array arr;
    createArray(&arr, max, size);
    metaData(&arr);
    assignValue(&arr);
    printArray(&arr);

    printf("<---------------- Insertion ---------------->\n");
    insert(&arr);
    printArray(&arr); 

    printf("<---------------- Deletion ---------------->\n");
    printf("Deleted Value: %i\n", delete(&arr));
    printArray(&arr);

    return 0;
}