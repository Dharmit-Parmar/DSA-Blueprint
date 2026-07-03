class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
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
};