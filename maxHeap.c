#include <stdio.h>

// Swap
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Display
void display(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ----> %i\n", i, arr[i]);
}

// Max-Heapify
void maxHeapify(int* arr, int size, int lastInternalNode)
{
    // Largest Node in a single Parent-Children Relation before Comparison 
    int largest = lastInternalNode;

    // Left Child Node
    int l = lastInternalNode * 2 + 1;

    // Right Child Node
    int r = lastInternalNode * 2 + 2;

    // Comparisons between parent and children to find Largest Node
    if (l <= size && arr[l] > arr[largest])
        largest = l;
    if (r <= size && arr[r] > arr[largest])
        largest = r;

    // Swap and Maintain Max-Heap Property
    if (largest != lastInternalNode)
    {
        // Swap
        swap(&arr[largest], &arr[lastInternalNode]);

        // Maintain Max-Heap Property in Nodes below after Swap
        maxHeapify(arr, size, largest);
    }
}

// Max-Heap Sort
void maxHeapSort(int* arr, int size)
{
    // Converting arr into Max Heap by using Max Heapify
    printf("\n----- Max Heapified -----\n");
    for (int i = (size - 2) / 2; i >= 0; i--)
        maxHeapify(arr, size, i);
    display(arr, size);

    // Heap Sort
    printf("\n----- Heap Sort -----\n");
    for (int i = size; i > 1; i--)
    {
        // Swap
        swap(&arr[0], &arr[i - 1]);

        // Maintain Max-Heap Property in Nodes below after Swap
        maxHeapify(arr, i - 2, 0);
    }
    display(arr, size);
}

int main()
{
    // Buffer to collect data from User
    int buffer[100];
    int size = 0;

    // Taking Input from User until user input -1
    do
    {
        // Getting input on size index
        printf("Enter the Number: ");
        scanf("%i", &buffer[size]);
    }
    while (buffer[size++] != -1);

    // Removing -1 from buffer
    size--;

    // Max-Heap Sort
    maxHeapSort(buffer, size);

    return 0;
}