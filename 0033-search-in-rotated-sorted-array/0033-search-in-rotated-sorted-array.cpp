// LeetCode 33 - Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: muteeba4266

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;

            // Step 1: Check if the left half [low...mid] is sorted
            if (nums[low] <= nums[mid]) {
                // Step 2: Check if target is within the sorted left half
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Step 1b: The right half [mid...high] must be sorted
            else {
                // Step 2b: Check if target is within the sorted right half
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};