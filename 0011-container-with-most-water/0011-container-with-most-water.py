# LeetCode 11 - Container With Most Water
# https://leetcode.com/problems/container-with-most-water/
# Author: muteeba4266

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        left = 0
        right = len(height) - 1
        
        while left < right:

            width = right - left
            current_height = min(height[left], height[right])
            current_area = width * current_height
      
            max_area = max(max_area, current_area)
            

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return max_area