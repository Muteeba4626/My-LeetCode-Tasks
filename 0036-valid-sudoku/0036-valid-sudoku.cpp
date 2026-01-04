// LeetCode 36 - Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/
// Author: muteeba4266

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use boolean arrays to track seen digits 1-9 (indexed 0-8)
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int num = board[r][c] - '1'; // Convert char '1'-'9' to int 0-8
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Check if the number already exists in current row, column, or box
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
};