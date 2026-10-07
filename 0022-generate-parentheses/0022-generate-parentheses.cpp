class Solution {
public:
    unordered_set<string> st;
    void solve(int& n, int count, string re) {
        if (2 * n == re.size() && !count) {
            st.insert(re);
            return;
        }

        if (count < 0 || count > (2 * n - re.length()))
            return;

        solve(n, count + 1, re + "(");

        solve(n, count - 1, re + ')');
    }
    vector<string> generateParenthesis(int n) {
        st.clear();
        solve(n, 0, "");

        return vector<string>(st.begin(), st.end());
    }
};