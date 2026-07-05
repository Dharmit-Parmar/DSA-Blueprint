class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i{0}, j{0};

        while (i < n && j < n) {
            if (nums[i] != 0) {
                i++; // i is looking for a zero, skip non-zeros
            } else if (nums[j] == 0 || j < i) {
                j++; // j needs to be ahead of i and looking for a non-zero
            } else {
                // If we reach here, nums[i] is 0 and nums[j] is non-zero
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
    }
};