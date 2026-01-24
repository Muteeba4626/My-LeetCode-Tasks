class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // Use unsigned long to prevent overflow during intermediate steps, 
        // though the final answer is guaranteed to fit in an int.
        vector<unsigned long long> dp(n + 1, 0);
        
        // Base case: An empty t can be formed by any prefix of s in 1 way (delete everything)
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            // We iterate backwards to use the results from the previous 'i' 
            // without needing a full 2D matrix.
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // If they don't match, dp[j] remains dp[j] (equivalent to dp[i-1][j])
            }
        }
        
        return (int)dp[n];
    }
};