// LeetCode 315 - Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Author: muteeba4266

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> indices(n);
        
        // Initialize indices to track original positions
        for (int i = 0; i < n; i++) indices[i] = i;
        
        vector<int> temp(n);
        mergeSort(nums, indices, temp, counts, 0, n - 1);
        
        return counts;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& indices, vector<int>& temp, vector<int>& counts, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(nums, indices, temp, counts, left, mid);
        mergeSort(nums, indices, temp, counts, mid + 1, right);
        
        merge(nums, indices, temp, counts, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& indices, vector<int>& temp, vector<int>& counts, int left, int mid, int right) {
        int i = left;      // Left subarray pointer
        int j = mid + 1;   // Right subarray pointer
        int k = left;      // Temp array pointer
        int rightCount = 0; // Number of elements from right side smaller than left side elements

        while (i <= mid && j <= right) {
            if (nums[indices[j]] < nums[indices[i]]) {
                // Element on the right is smaller
                rightCount++;
                temp[k++] = indices[j++];
            } else {
                // Element on the left is smaller or equal
                // Add the current count of smaller right-side elements to this index
                counts[indices[i]] += rightCount;
                temp[k++] = indices[i++];
            }
        }

        // Clean up remaining elements
        while (i <= mid) {
            counts[indices[i]] += rightCount;
            temp[k++] = indices[i++];
        }
        while (j <= right) {
            temp[k++] = indices[j++];
        }

        // Copy back to original indices array
        for (int p = left; p <= right; p++) {
            indices[p] = temp[p];
        }
    }
};