class Solution {
public:
    int rows, cols;
    int memo[201][201];
    int dirs[5] = {-1, 0, 1, 0, -1};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        memset(memo, 0, sizeof(memo));
        
        int maxPath = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxPath = max(maxPath, dfs(matrix, i, j));
            }
        }
        return maxPath;
    }

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (memo[r][c] != 0) return memo[r][c];
        
        int currentMax = 1;
        for (int k = 0; k < 4; k++) {
            int nr = r + dirs[k];
            int nc = c + dirs[k + 1];
            
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
                currentMax = max(currentMax, 1 + dfs(matrix, nr, nc));
            }
        }
        return memo[r][c] = currentMax;
    }
};