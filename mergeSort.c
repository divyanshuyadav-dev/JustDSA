#include <stdio.h>

// Display
void display(int* arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%i\t", arr[i]);
    printf("\n");
}

// Merge
void merge(int* arr, int start, int mid, int end)
{
    // Calculating Size of Both Left Portion and Right Portion of Array
    int size1 = mid - start + 1;
    int size2 = end - mid;

    // Creating Temp Array
    int left[size1], right[size2];

    // Copy Data to Temp arrays Left and Right
    for (int i = 0; i < size1; i++)
        left[i] = arr[start + i];
    for (int i = 0; i < size2; i++)
        right[i] = arr[mid + 1 + i];

    // Merging Array 
    int i = 0, j = 0, k = start;
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }

    // Copying the remaining element from Left Array
    while (i < size1)
        arr[k++] = left[i++];
    
    // Copying the remaining element from Right Array
    while (j < size2)
        arr[k++] = right[j++];
    
}

// Merge Sort
void mergeSort(int* arr, int start, int end)
{
    if (start != end)
    {
        int mid = start + (end - start) / 2;

        // Micro Sorting
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
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

    // Merge Sort
    printf("\n----- Merge Sort -----\n");
    mergeSort(arr, 0, len - 1);

    // Display
    display(arr, len);
    return 0;
}
