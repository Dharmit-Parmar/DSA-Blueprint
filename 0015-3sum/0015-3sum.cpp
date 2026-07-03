class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());  // sort the array first

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicate first elements

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int currentSum = nums[i] + nums[j] + nums[k];

                if (currentSum == 0) {  // sum matches
                    result.push_back({nums[i], nums[j], nums[k]});

                    // skip duplicates for second and third elements
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                } else if (currentSum < 0) {
                    j++;  // need bigger sum
                } else {
                    k--;  // need smaller sum
                }
            }
        }

        return result;
    }
};