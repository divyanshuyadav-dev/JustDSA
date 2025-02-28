#include <iostream>
using namespace std;

// Cache - Stores Result of Recurring Sub-Problems
int cache[100];

// Fibonacci Value using Dynamic Programming
int fibDP(int n)
{
    // Terminating Condition
    if (n == 1 || n == 0)
        return n;

    // bn -> before n -> n - 1
    int bn = n - 1;
    if (cache[bn] == 0)
        cache[bn] = fibDP(bn);
    cache[n] = cache[bn] + cache[bn - 1];
    return cache[n];
}

int main()
{
    // Fibonacci Value using Dynamic Programming
    int n;
    cout << "Enter the Index for Fibonacci Value: ";
    cin >> n;

    cout << endl << "----- Fibonacci Value using Dynamic Programming -----" << endl;
    cout << "Fibonacci Value at Index " << n << "th is " << fibDP(n);
}