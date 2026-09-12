/*
    PROBLEM: Pascal's Triangle Row Sum & Prime Check

     a C++ program that does the following using ONLY for loops
    (no while loops, no recursion):

    1. Print Pascal's Triangle up to N rows (take N as input from the user).
    2. For each row, calculate the sum of all elements in that row.
    3. Check whether that row sum is a prime number, and print "Prime"
       or "Not Prime" next to it.

    Example (N = 5):

    Row 1: 1                        Sum = 1   -> Not Prime
    Row 2: 1 1                      Sum = 2   -> Prime
    Row 3: 1 2 1                    Sum = 4   -> Not Prime
    Row 4: 1 3 3 1                  Sum = 8   -> Not Prime
    Row 5: 1 4 6 4 1                Sum = 16  -> Not Prime
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime using a for loop
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> n;

    for (int row = 0; row < n; row++) {
        long long value = 1;
        long long rowSum = 0;

        cout << "Row " << row + 1 << ": ";

        for (int col = 0; col <= row; col++) {
            cout << value << " ";
            rowSum += value;
            // Update value to the next binomial coefficient in the row
            value = value * (row - col) / (col + 1);
        }

        cout << "  Sum = " << rowSum << " -> "
             << (isPrime(rowSum) ? "Prime" : "Not Prime") << endl;
    }

    return 0;
}

/*
    SAMPLE OUTPUT (N = 5):

    Enter number of rows for Pascal's Triangle: 5
    Row 1: 1   Sum = 1 -> Not Prime
    Row 2: 1 1   Sum = 2 -> Prime
    Row 3: 1 2 1   Sum = 4 -> Not Prime
    Row 4: 1 3 3 1   Sum = 8 -> Not Prime
    Row 5: 1 4 6 4 1   Sum = 16 -> Not Prime
*/
