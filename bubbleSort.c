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

// Bubble Sort
void bubbleSort(int* arr, int len)
{
    printf("\n----- Bubble Sort -----\n");
    int swaps;

    for (int j = 0; j < len - 1; j++)
    {
        swaps = 0;

        // Single Pass - Sort The Heaviest Bubble
        for (int i = 0; i < len - 1; i++)
        {
            int next = i + 1;
            if (arr[i] > arr[next])
            {
                // Swap
                swap(&arr[i], &arr[next]);

                swaps = 1;
            }
        }

        // Sorted
        if (swaps == 0)
            return;
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

    // Bubble Sort
    bubbleSort(arr, len);

    // Display
    display(arr, len);
    return 0;
}
