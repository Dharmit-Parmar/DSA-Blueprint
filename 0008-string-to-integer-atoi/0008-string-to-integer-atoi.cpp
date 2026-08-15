class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        bool isNeg = false;

        int ans = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                isNeg = true;
            }
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return isNeg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }

        if (isNeg) {
            ans = ans * (-1);
        }

        return ans;
    }
};