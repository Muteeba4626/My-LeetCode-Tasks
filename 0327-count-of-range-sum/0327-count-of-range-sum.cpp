// LeetCode 327 - Count of Range Sum
// https://leetcode.com/problems/count-of-range-sum/
// Author: muteeba4266

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        return mergeSort(prefixSums, 0, n, lower, upper);
    }

private:
    int mergeSort(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end <= start) return 0;
        
        int mid = start + (end - start) / 2;
        int count = mergeSort(sums, start, mid, lower, upper) + 
                    mergeSort(sums, mid + 1, end, lower, upper);
        
        // Count pairs across the mid point
        int j = mid + 1, k = mid + 1, t = mid + 1;
        vector<long> cache(end - start + 1);
        int r = 0;
        
        for (int i = start; i <= mid; ++i) {
            // Find the range [j, k) in the right half
            while (j <= end && sums[j] - sums[i] < lower) j++;
            while (k <= end && sums[k] - sums[i] <= upper) k++;
            
            // Standard merge logic to sort the array
            while (t <= end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r++] = sums[i];
            
            count += k - j;
        }
        
        // Copy remaining elements from the right half for sorting
        while (t <= end) cache[r++] = sums[t++];
        
        // Copy sorted cache back to the original array
        for (int i = 0; i < r; ++i) {
            sums[start + i] = cache[i];
        }
        
        return count;
    }
};