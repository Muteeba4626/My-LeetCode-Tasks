// LeetCode 22 - Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
// Author: muteeba4266

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        // Base case: If the current string length reaches 2*n, it's a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // If we can still add an opening parenthesis
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back(); // Backtrack
        }

        // If we can add a closing parenthesis (must have more open than closed)
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back(); // Backtrack
        }
    }
};