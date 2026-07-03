class Solution {
public:
    /**
     * Removes all occurrences of 'val' from the vector 'nums' in-place.
     * Maintains the relative order of the elements that are not equal to 'val'.
     * Returns the new length of the vector containing the remaining elements.
     * Time Complexity: O(n) | Space Complexity: O(1)
     *
     * LOGIC: Uses a "seek and shift" approach with two pointers (i, j).
     * 'i' finds the position of a value to remove, while 'j' looks ahead
     * to find the next valid value to swap into that position.
     */
    int removeInOrder(vector<int>& nums, int val) {
        int n = nums.size();
        int i{0}, j{0};

        while (i < n && j < n) {
            while (i < n && nums[i] != val)
                i++;

            j = max(j, i);

            while (j < n && nums[j] == val)
                j++;

            if (i < n && j < n)
                swap(nums[i], nums[j]);
        }

        return i;
    }

    /**
     * Removes all occurrences of 'val' from the vector 'nums' in-place.
     * Does NOT maintain the relative order of elements.
     * Returns the new length of the vector containing the remaining elements.
     * Time Complexity: O(n) | Space Complexity: O(1)
     *
     * LOGIC: Uses a bidirectional approach. 'i' scans from the start and 'j'
     * from the end. When a target is found at 'i', it is swapped with the
     * element at 'j', effectively "filling the hole" with elements from the
     * back of the array.
     */
    int removeInAnyOrder(vector<int>& nums, int val) {
        int n = nums.size();
        int i{0}, j{n - 1};

        while (i <= j) {
            if (nums[i] != val)
                i++;
            else if (nums[j] == val)
                j--;
            else {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        return i;
    }

    /*
     * COMPARISON:
     * - removeInOrder preserves the original sequence of remaining elements;
     *   removeInAnyOrder does not.
     * - removeInAnyOrder is generally more efficient in practice because it
     *   minimizes unnecessary swaps by utilizing the end of the array to fill
     *   gaps, whereas removeInOrder must perform more lookups to maintain
     * order.
     */

    /**
     * Helper function that wraps removeInAnyOrder to perform the
     * standard element removal operation.
     */
    int removeElement(vector<int>& nums, int val) {
        return removeInAnyOrder(nums, val);
    }
};