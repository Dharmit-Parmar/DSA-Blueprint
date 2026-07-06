class Solution {
public:
    /**
     * @brief Searches for a target in a rotated sorted array.
     * @details Uses binary search to first locate the pivot (minimum element)
     *          to understand the rotation, then performs binary search on the
     *          correct sorted sub-segment.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(log n)
     * - Space Complexity: O(1)
     */
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;

        int s = 0, e = n - 1;

        // 1. Find the pivot index (the index of the minimum element)
        while (s < e) {
            int m = s + (e - s) / 2;
            if (nums[m] > nums[e])
                s = m + 1;
            else
                e = m;
        }

        int pivot = s;

        // 2. Determine which half to search
        // If target is in the right sorted part [pivot, n-1]
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            s = pivot;
            e = n - 1;
        }
        // Otherwise, it must be in the left sorted part [0, pivot-1]
        else {
            s = 0;
            e = pivot - 1;
        }

        // 3. Perform standard Binary Search on the selected range
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }

        return -1; // Target not found
    }
};