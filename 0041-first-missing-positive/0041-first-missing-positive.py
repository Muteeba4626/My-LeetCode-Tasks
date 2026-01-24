class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        
        for i in range(n):
            # While the current number is in the valid range [1, n]
            # AND it is not already at its correct index (nums[i] - 1)
            # AND the target spot doesn't already have the correct number (prevents infinite loop)
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                # Swap the number to its "rightful home"
                correct_idx = nums[i] - 1
                nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
        
        # After sorting, the first index that doesn't match its value is the winner
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        
        # If all spots 1 to n are filled, the missing one is n + 1
        return n + 1