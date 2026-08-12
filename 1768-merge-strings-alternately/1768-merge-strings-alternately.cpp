class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i{0}, j{0};
        int n = word1.size();
        int m = word2.size();
        string ans = "";

        // using 2 pointer approach

        while (i < n && j < m) {
            ans += word1[i++];
            ans += word2[j++];
        }

        while (i < n) {
            ans += word1[i++];
        }

        while (j < m) {
            ans += word2[j++];
        }
        return ans;
    }
};