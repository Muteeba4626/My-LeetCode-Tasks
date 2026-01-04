// LeetCode 174 - Dungeon Game
// https://leetcode.com/problems/dungeon-game/
// Author: muteeba4266

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        // dp[i][j] represents the min health needed before entering room (i, j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));

        // Base cases: To survive after the princess room, the knight needs at least 1 HP
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Determine min health needed to leave this room
                int min_exit_hp = min(dp[i + 1][j], dp[i][j + 1]);
                
                // Health needed before entering this room
                // Must be at least 1, even if room contains a large power-up
                dp[i][j] = max(1, min_exit_hp - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};

