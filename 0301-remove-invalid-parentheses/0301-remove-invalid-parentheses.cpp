class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        prune(s, res, 0, 0, {'(', ')'});
        return res;
    }

private:
    void prune(string s, vector<string>& res, int start, int lastRem,
               vector<char> pat) {
        int bal = 0;

        for (int i = start; i < s.size(); ++i) {
            if (s[i] == pat[0])
                bal++;
            if (s[i] == pat[1])
                bal--;

            if (bal < 0) {
                for (int j = lastRem; j <= i; ++j) {
                    if (s[j] == pat[1] &&
                        (j == lastRem || s[j - 1] != pat[1])) {
                        prune(s.substr(0, j) + s.substr(j + 1), res, i, j, pat);
                    }
                }
                return;
            }
        }

        string rev(s.rbegin(), s.rend());

        if (pat[0] == '(') {
            prune(rev, res, 0, 0, {')', '('});
        } else {
            res.push_back(rev);
        }
    }
};