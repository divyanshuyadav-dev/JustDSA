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

// Insertion Sort
void insertionSort(int* arr, int len)
{
    printf("\n----- Insertion Sort -----\n");

    for (int i = 1; i < len; i++)
        // Swap
        for (int j = i; j >= 1 && arr[j - 1] > arr[j]; j--)
            swap(&arr[j - 1], &arr[j]);
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

    // Insertion Sort
    insertionSort(arr, len);

    // Display
    display(arr, len);
    return 0;
}
