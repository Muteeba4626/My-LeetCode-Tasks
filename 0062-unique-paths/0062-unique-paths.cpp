class Solution {
public:
    int uniquePaths(int m, int n) {
        // We only need one row to store intermediate results
        vector<int> row(n, 1);
        
        // Iterate through each row starting from the second one
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Current cell = Paths from Top (already in row[j]) + Paths from Left (row[j-1])
                row[j] += row[j - 1];
            }
        }
        
        return row[n - 1];
    }
};