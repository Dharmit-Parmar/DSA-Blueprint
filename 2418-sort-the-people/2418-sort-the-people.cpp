class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> data;
        int n = names.size();

        // 1. Pair up heights with names (height first so it sorts by height)
        for (int i = 0; i < n; i++) {
            data.push_back({heights[i], names[i]});
        }

        // 2. Sort in descending order (tallest first)
        sort(data.rbegin(), data.rend());

        // 3. Extract just the names into the result vector
        vector<string> result;
        for (int i = 0; i < n; i++) {
            result.push_back(data[i].second);
        }

        return result;
    }
};