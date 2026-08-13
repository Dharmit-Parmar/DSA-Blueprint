class Solution {
public:
    bool isSubsequence(string s, string t) {

        if (s.empty())
            return true;

        if (s.size() > t.size())
            return false;

        int n = s.size();
        int m = t.size();
        int i{0}, j{0};

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return (i == n);
    }
};