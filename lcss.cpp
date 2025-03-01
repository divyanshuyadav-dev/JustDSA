#include <iostream>
#include <vector>
using namespace std;

// Longest Common SubSequence using Dynamic Programming
int lcssDP(vector <vector<int>> cache, string &a, string &b, int iA, int iB)
{
    // Terminating Condition - No Character Left to Compare in One of the String or Both
    if (iA == 0 || iB == 0)
        return 0;

    // "cache[iA][iB] == -1" ----> Problem/Sub-Problem is NOT Solved yet
    // "cache[iA][iB] != -1" ----> Problem/Sub-Problem is ALREADY Solved and Stored in Cache
    if (cache[iA][iB] != -1)
        return cache[iA][iB];

    // Comparing Characters from Strings A and B
    if (a[iA - 1] == b[iB - 1])
        return cache[iA][iB] = 1 + lcssDP(cache, a, b, iA - 1, iB - 1);
    
    if (cache[iA - 1][iB] == -1)
        cache[iA - 1][iB] = lcssDP(cache, a, b, iA - 1, iB);
    if (cache[iA][iB - 1] == -1)
        cache[iA][iB - 1] = lcssDP(cache, a, b, iA, iB - 1);

    return cache[iA][iB] = max(cache[iA - 1][iB], cache[iA][iB - 1]);
}

// Main
int main()
{
    // String
    string A, B;
    cout << "String A: ";
    cin >> A;
    cout << "String B: ";
    cin >> B;
    
    // Length of A and B
    int lenA = A.length();
    int lenB = B.length();
    
    // Cache (2D) - Stores Result of Recurring Sub-Problems
    vector<vector<int>> cache(lenA + 1, vector<int>(lenB + 1, -1));
    
    // Longest Common SubSequence
    cout << endl << "----- Longest Common SubSequence -----" << endl;
    cout << "-> " << lcssDP(cache, A, B, lenA, lenB) << endl;
}