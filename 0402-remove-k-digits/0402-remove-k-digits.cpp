class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k)
            return "0";

        string re = "";

        for (char digit : num) {

            while (!re.empty() && re.back() > digit && k > 0) {
                re.pop_back();
                k--;
            }
            re.push_back(digit);
        }

        while (k > 0 && !re.empty()) {
            re.pop_back();
            k--;
        }

        int start = 0;
        while (start < re.length() && re[start] == '0') {
            start++;
        }

        re = re.substr(start);

        return re.empty() ? "0" : re;
    }
};
