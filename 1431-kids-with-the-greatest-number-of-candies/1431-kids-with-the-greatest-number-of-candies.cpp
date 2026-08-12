class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> ans;

        // now finding the values which are true
        for (const auto c : candies) {
            ans.push_back((c + extraCandies) >= maxCandies);
        }

        return ans;
    }
};