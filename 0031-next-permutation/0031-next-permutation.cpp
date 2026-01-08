// LeetCode 31 - Next Permutation
// https://leetcode.com/problems/next-permutation/
// Author: muteeba4266

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first element from the right that is smaller than its successor
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find the element from the right that is just larger than nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Swap pivot with successor
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix (everything after index i)
        // If i was -1, the entire array is reversed (handles the last permutation case)
        reverse(nums.begin() + i + 1, nums.end());
    }
};