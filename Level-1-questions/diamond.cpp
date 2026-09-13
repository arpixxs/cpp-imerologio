/*
    QUESTION

    Print the following diamond-shaped pattern of numbers for a given odd
    integer N (number of rows in the widest part), using ONLY for loops
    (no while/do-while, no recursion).

    Rules:
    1. The pattern is a diamond made of numbers (not stars).
    2. Each row's numbers count up from 1 to the row's "width" and then
       back down to 1 (like 1 2 3 2 1).
    3. The diamond expands from 1 row of width 1 at the top to N rows
       of width N in the middle, then shrinks back down to width 1.
    4. Proper leading spaces must be added so the diamond is centered.

    Example for N = 5:

        1
       121
      12321
     1234321
    123454321
     1234321
      12321
       121
        1

    Constraints:
    - N will always be an odd number >= 1.
    - Solve it using nested for loops only.
*/

#include <iostream>
using namespace std;

void printDiamond(int n) {
    // Upper half (including middle row): widths 1, 3, 5, ..., n
    for (int i = 1; i <= n; i += 2) {
        // Leading spaces
        for (int s = 0; s < (n - i) / 2; s++) {
            cout << " ";
        }

        // Ascending numbers 1..mid
        int mid = (i + 1) / 2;
        for (int num = 1; num <= mid; num++) {
            cout << num;
        }

        // Descending numbers back to 1
        for (int num = mid - 1; num >= 1; num--) {
            cout << num;
        }

        cout << endl;
    }

    // Lower half (mirror, excluding the middle row): widths n-2, n-4, ..., 1
    for (int i = n - 2; i >= 1; i -= 2) {
        for (int s = 0; s < (n - i) / 2; s++) {
            cout << " ";
        }

        int mid = (i + 1) / 2;
        for (int num = 1; num <= mid; num++) {
            cout << num;
        }

        for (int num = mid - 1; num >= 1; num--) {
            cout << num;
        }

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter an odd number N: ";
    cin >> n;

    if (n % 2 == 0 || n < 1) {
        cout << "N must be a positive odd integer." << endl;
        return 1;
    }

    printDiamond(n);

    return 0;
}