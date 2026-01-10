// LeetCode 378 - Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-sorted-matrix/
// Author: muteeba4266

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int result = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count elements <= mid using Staircase Search
            if (countLessEqual(matrix, mid, n) >= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int row = n - 1; // Start from bottom-left
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                // If this element is <= mid, then all elements above it 
                // in the same column are also <= mid.
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};