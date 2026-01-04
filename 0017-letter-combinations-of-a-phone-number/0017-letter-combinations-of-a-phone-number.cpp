// LeetCode 17 - Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: muteeba4266

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Keypad mapping based on standard telephone buttons
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> result;
        string current;
        backtrack(digits, mapping, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& digits, const vector<string>& mapping, int index, string& current, vector<string>& result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to the current digit
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);           // Choose
            backtrack(digits, mapping, index + 1, current, result); // Explore
            current.pop_back();              // Unchoose (Backtrack)
        }
    }
};