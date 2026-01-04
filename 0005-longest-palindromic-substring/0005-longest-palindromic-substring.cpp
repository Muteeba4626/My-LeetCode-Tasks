// LeetCode 5 - Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/
// Author: muteeba4266

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int start = 0, maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes (center is s[i])
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes (center is between s[i] and s[i+1])
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                // Calculate the start index of the palindrome
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Length of the palindrome is right - left - 1
        return right - left - 1;
    }
};