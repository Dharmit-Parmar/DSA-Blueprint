class Solution {
public:
    /**
     * @brief Given an array of integers nums, move all the even integers at the
     * beginning of the array followed by all the odd integers.
     *
     * METHODOLOGY: Two-Pointer Approach
     * 1. Initialize a left pointer `l` at the start and a right pointer `r` at
     * the end of the array.
     * 2. Increment `l` while the element is even (already in the correct
     * position).
     * 3. Decrement `r` while the element is odd (already in the correct
     * position).
     * 4. When `l` points to an odd number and `r` points to an even number,
     * swap them and move both pointers inward.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> Each element is visited at most once by the
     * pointers.
     * - Space Complexity: O(1) -> In-place sorting using constant extra space.
     */
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            // Skip even numbers on the left side
            while (l < r && nums[l] % 2 == 0) {
                l++;
            }
            // Skip odd numbers on the right side
            while (l < r && nums[r] % 2 != 0) {
                r--;
            }
            // Swap the odd number from the left with the even number from the
            // right
            if (l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }

        return nums;
    }
};