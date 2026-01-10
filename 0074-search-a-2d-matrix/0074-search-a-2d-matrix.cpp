// LeetCode 74 - Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
// Author: muteeba4266

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns
        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Map 1D index back to 2D row and column
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};