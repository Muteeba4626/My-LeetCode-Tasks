class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Bitmasks to track columns, main diagonals, and anti-diagonals
        // (1 << n) - 1 creates a mask of 'n' ones (e.g., for n=4, 1111)
        solve(0, 0, 0, 0, (1 << n) - 1, count);
        return count;
    }

private:
    void solve(int row, int cols, int main_diag, int anti_diag, int mask, int& count) {
        // Base case: If all rows are filled, we found a valid solution
        if (cols == mask) {
            count++;
            return;
        }

        // 'pos' contains all 1s at positions where it is safe to place a queen
        // It combines all conflicts and flips them using ~
        int pos = mask & ~(cols | main_diag | anti_diag);

        while (pos > 0) {
            // Get the lowest set bit (pick one safe column)
            int p = pos & -pos;
            
            // Mark this column as used and recurse to the next row
            // main_diag is shifted left and anti_diag is shifted right for the next row
            solve(row + 1, 
                  cols | p, 
                  (main_diag | p) << 1, 
                  (anti_diag | p) >> 1, 
                  mask, count);
            
            // Remove the used bit to try the next safe position in this row
            pos -= p;
        }
    }
};