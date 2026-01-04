# LeetCode 53 - Maximum Subarray
# https://leetcode.com/problems/maximum-subarray/
# Author: muteeba4266

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize max_sum with a very small value or the first element
        max_sum = nums[0]
        current_sum = 0
        
        for num in nums:
            # Add current element to our running total
            current_sum += num
            
            # Update max_sum if the current_sum is better
            if current_sum > max_sum:
                max_sum = current_sum
            
            # If current_sum drops below 0, reset it. 
            # A negative sum will never contribute to a larger subarray sum later.
            if current_sum < 0:
                current_sum = 0
                
        return max_sum