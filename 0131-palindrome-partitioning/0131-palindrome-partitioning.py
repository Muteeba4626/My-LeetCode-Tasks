class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        
        def backtrack(start, path):
            # Base case: if we've reached the end of the string
            if start == len(s):
                res.append(list(path))
                return
            
            # Explore every possible substring starting from 'start'
            for end in range(start + 1, len(s) + 1):
                substring = s[start:end]
                # Only recurse if the current substring is a palindrome
                if self.is_palindrome(substring):
                    path.append(substring)
                    backtrack(end, path)
                    path.pop() # Backtrack to try the next split point
        
        backtrack(0, [])
        return res

    def is_palindrome(self, sub):
        return sub == sub[::-1]