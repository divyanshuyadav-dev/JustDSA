#include <stdio.h>

// Display
void display(int* arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%i\t", arr[i]);
    printf("\n");
}

// Swap
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort
void selectionSort(int* arr, int len)
{
    printf("\n----- Selection Sort -----\n");

    for (int i = 0; i < len - 1; i++)
    {
        // Index of Smallest Element
        int smallest = i;

        // Find new Smallest Element
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[smallest])
                smallest = j;

        // Swap if new Smallest Element is found
        if (smallest != i)
            swap(&arr[i], &arr[smallest]);
    }
}

int main()
{
    int arr[101];
    int len = 0;

    // Take Input from User
    do
    {
        printf("Enter the Number: ");
        scanf("%i", &arr[len]);
    }
    while (arr[len++] != -1);

    // Removing -1
    len--;

    // Selection Sort
    selectionSort(arr, len);

    // Display
    display(arr, len);
    return 0;
}
