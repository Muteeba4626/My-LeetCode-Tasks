class Solution {
    unordered_map<string, bool> memo;

public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        
        // Base Cases
        if (s1 == s2) return true;
        if (n == 1) return false;
        
        // Check Memoization
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];
        
        // Pruning: Check if they have the same characters
        int count[26] = {0};
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return memo[key] = false;
        }

        // Try every possible split point
        for (int i = 1; i < n; i++) {
            // Case 1: No swap at this level
            // s1: [0...i][i...n]  vs  s2: [0...i][i...n]
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            
            // Case 2: Substrings were swapped at this level
            // s1: [0...i][i...n]  vs  s2: [n-i...n][0...n-i]
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};