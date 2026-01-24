import math

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        # Create a list of numbers [1, 2, ..., n]
        numbers = [str(i) for i in range(1, n + 1)]
        # Precompute factorials for efficiency
        factorials = [1] * n
        for i in range(1, n):
            factorials[i] = factorials[i-1] * i
        
        # Convert k to 0-indexed for easier calculation
        k -= 1
        result = []
        
        # Determine each digit of the permutation
        for i in range(n - 1, -1, -1):
            # Calculate how many permutations are in each 'block'
            idx = k // factorials[i]
            k %= factorials[i]
            
            # Select the number at the calculated index
            result.append(numbers.pop(idx))
            
        return "".join(result)