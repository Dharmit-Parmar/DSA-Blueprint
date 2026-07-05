class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        // Base case if there's only one element
        if (n == 1)
            return (double)nums[0];

        // Step 1: Transform nums into a Prefix Sum array
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        // Step 2: Initialize max_avg with the very first window's average
        // The sum of the first k elements (indices 0 to k-1) is now stored at
        // nums[k-1]
        double max_avg = (double)nums[k - 1] / k;
        double avg;
        // Step 3: Check all other windows of size k
        // The window ends at index 'i'. It starts at index 'i - k + 1'.
        for (int i = k; i < n; i++) {
            // Sum of elements from (i - k + 1) to i
            avg = (double)(nums[i] - nums[i - k]) / k;

            max_avg = max(max_avg, avg);
        }

        return max_avg;
    }
};