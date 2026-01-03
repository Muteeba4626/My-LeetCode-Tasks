// LeetCode 3107 - Minimum Operations to Make Median of Array Equal to K
// https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/
// Difficulty: Medium
// Language: C++
// Author: muteeba4266

lass Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long ops = 0;
        int mid = n / 2;
        
        ops += abs(nums[mid] - k);
        nums[mid] = k;
        
        for (int i = mid - 1; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                ops += (nums[i] - nums[i + 1]);
                nums[i] = nums[i + 1];
            } else {
                break;
            }
        }
        
        for (int i = mid + 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                ops += (nums[i - 1] - nums[i]);
                nums[i] = nums[i - 1];
            } else {
                break;
            }
        }
        
        return ops;
    }
};
 
