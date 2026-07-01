class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        // first we apply the binnary search for the finding the element
        int s{0}, e{n - 1}, m{0};
        int j{0}, i{0}, foundIdx{-1};
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                foundIdx = m;
                break; // We found an instance, now break to expand
            } else if (nums[m] < target) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        // If we never found the target, return early
        if (foundIdx == -1)
            return {-1, -1};
        i = foundIdx;
        j = foundIdx;
        // now we have find the elemnt let just check the index
        while (i > 0 && nums[i - 1] == target) {
            i--;
        }
        // Move right as long as we stay in bounds and the element matches
        while (j < n - 1 && nums[j + 1] == target) {
            j++;
        }

        return {i, j};
    }
};