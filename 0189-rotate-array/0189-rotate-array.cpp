class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());

        // reverse the first k elemetn

        reverse(nums.begin(), nums.begin() + k);

        // no reverse the left over element
        reverse(nums.begin() + k, nums.end());
    }
};