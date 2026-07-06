class Solution {
public:
    /**
     * @brief Finds the minimum element in a rotated sorted array.
     *
     * METHODOLOGY: Binary Search
     * In a rotated sorted array, the "inflection point" where the rotation
     * occurs is where the minimum value resides. We compare the middle element
     * with the rightmost element to determine which side of the array is
     * sorted. If nums[m] > nums[e], the rotation point must be in the right
     * half.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(log n) -> Standard binary search division.
     * - Space Complexity: O(1) -> Only uses a few integer pointers.
     */
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;

        // Loop stops as soon as s == e (they converge on the minimum)
        while (s < e) {
            int m = s + (e - s) / 2;

            // If mid is greater than the end element, the drop (minimum)
            // MUST be somewhere to the right of mid.
            if (nums[m] > nums[e]) {
                s = m + 1; // Safe to skip m because it's larger than nums[e]
            }
            // If mid is less than or equal to the end element, the minimum
            // is either at mid or somewhere to the left of mid.
            else {
                e = m; // Keep m in play because it could be the minimum
            }
        }

        // When s == e, both pointers point to the absolute minimum element
        return nums[s];
    }
};