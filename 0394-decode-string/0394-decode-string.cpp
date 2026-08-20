class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> stringStack;
        int dig{0};
        string curString = "";
        for (const auto e : s) {
            if (isdigit(e)) {
                dig = dig * 10 + (e - '0');
            }

            else if (e == '[') {
                num.push(dig);
                stringStack.push(curString);
                curString = "";
                dig = 0;
            } else if (e == ']') {
                string prevString = stringStack.top();
                stringStack.pop();
                int n = num.top();
                num.pop();

                string repeatedSegment = "";
                for (int i = 0; i < n; i++) {
                    repeatedSegment += curString;
                }

                curString = prevString + repeatedSegment;
            } else {
                curString += e;
            }
        }

        return curString;
    }
};