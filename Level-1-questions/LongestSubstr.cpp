/*
    Problem: Longest Substring Without Repeating Characters
    Level: 2 (Medium)

    Statement:
    Given a string s, find the length of the longest substring
    without repeating characters.

    Example 1:
    Input:  s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

    Example 2:
    Input:  s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

    Example 3:
    Input:  s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.

    Constraints:
    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols, and spaces.

    Approach: Sliding Window + Hash Map
    - Maintain a window [left, right] with all unique characters.
    - Expand right one step at a time.
    - If the character at right was already seen inside the current
      window, shrink the window by moving left just past its last
      occurrence.
    - Track the maximum window size seen so far.

    Time Complexity:  O(n)
    Space Complexity: O(min(n, charset size))
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
 {
    unordered_map<char, int> lastSeen; // char -> last index seen
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];

        // If c was seen inside the current window, move left past it
        if (lastSeen.count(c) && lastSeen[c] >= left) {
            left = lastSeen[c] + 1;
        }

        lastSeen[c] = right;
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() 
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}