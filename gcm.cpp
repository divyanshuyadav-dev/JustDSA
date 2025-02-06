// Learned this Method from the link below:
// https://youtu.be/Tzl0ELY_TiM?si=NQ5PFrMw9uSAepHU&t=312

#include <iostream>
using namespace std;

// Greatest Common Measure (GCM)
int gcm(int a, int b)
{
    if (a == b || b == 0)
        return a;
    if (a == 0)
        return b;
    if (a < b)
        gcm(a, b % a);
    else
        gcm(b, a % b);
}

// Main
int main()
{
    cout << "------- Greatest Common Measure (GCM) -------" << endl;
    
    // Taking Input from User
    int a, b;
    cout << "Enter First Number: ";
    cin >> a;
    cout << "Enter Second Number: ";
    cin >> b;

    // Result
    cout << "GCM of " << a << " and " << b << " is "<< gcm(a, b);
    return 0;
}