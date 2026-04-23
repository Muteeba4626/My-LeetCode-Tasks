class Solution:
    def solveSudoku(self, board):
        
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        
        empty = []
        
        # initialize
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    empty.append((i, j))
                else:
                    num = board[i][j]
                    rows[i].add(num)
                    cols[j].add(num)
                    boxes[(i//3)*3 + j//3].add(num)
        
        def solve(idx):
            if idx == len(empty):
                return True
            
            r, c = empty[idx]
            b = (r//3)*3 + c//3
            
            for num in '123456789':
                if num not in rows[r] and num not in cols[c] and num not in boxes[b]:
                    
                    board[r][c] = num
                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[b].add(num)
                    
                    if solve(idx + 1):
                        return True
                    
                    # backtrack
                    board[r][c] = '.'
                    rows[r].remove(num)
                    cols[c].remove(num)
                    boxes[b].remove(num)
            
            return False
        
        solve(0)