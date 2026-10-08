class Solution {
public:
    string removeOuterParentheses(string s) {
        int d = 0;
        string re = "";

        for (const char c : s) {
            if (c == '(') {
                if (d > 0)
                    re += c;
                d++;
            } else {
                if (d > 1)
                    re += c;
                d--;
            }
        }

        return re;
    }
};