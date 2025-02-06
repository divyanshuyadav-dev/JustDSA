#include <iostream>
using namespace std;

// Max-Min
typedef struct max_min
{
    int max;
    int min;
} max_min;

// Straight Max-Min / Recursive Max-Min
max_min recMinMax(int* a, int start, int end)
{
    max_min m;

    // Conquer
    if (start == end)
        // If ONLY ONE Element is in the Data Structure
        m.min = m.max = a[start];
    else if (start == end - 1)
    {
        // If ONLY TWO Elements is in the Data Structure
        if (a[start] > a[end])
        {
            m.max = a[start];
            m.min = a[end];
        }
        else
        {
            m.max = a[end];
            m. min = a[start];
        }
    }
    else
    {
        // If MANY Elements is in the Data Structure

        // Divide

        // Middle Element
        int mid = (start + end) / 2;
        max_min m1 = recMinMax(a, start, mid);
        max_min m2 = recMinMax(a, mid + 1, end);

        // Combine

        // Comparing for Max
        if (m1.max > m2.max)
            m.max = m1.max;
        else
            m.max = m2.max;

        // Comparing for Min
        if (m1.min < m2.min)
            m.min = m1.min;
        else
            m.min = m2.min;
    }
    return m;
}

// Display
void display(int* arr, int len)
{
    cout << "\n------- Input -------\n";
    for (int i = 0; i < len; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

// Main
int main()
{
    // Data Structure to Store Elements
    int arr[101];

    // Current Len
    int currLen = 0;

    // Take Input from User
    do
    {
        cout << "Enter the Value into Array: ";
        cin >> arr[currLen];
    }
    while (arr[currLen++] != -1);
    currLen--;

    // Display
    display(arr, currLen);

    // Straight Max-Min / Recursive Max-Min
    max_min result = recMinMax(arr, 0, --currLen);

    // Result
    cout << "\n------- Result -------\n";
    cout << "Max: " << result.max << endl;
    cout << "Min: " << result.min << endl;
    
    return 0;
}