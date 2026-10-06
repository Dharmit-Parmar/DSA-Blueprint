class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        stack<char> st;
        int count{0};

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    count++;
                }
            }
        }

        return (count + st.size());
    }
};