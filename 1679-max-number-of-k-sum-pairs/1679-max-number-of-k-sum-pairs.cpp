class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int> st;
        int count{0};

        for (int num : nums) {
            int target = k - num;

            auto it = st.find(target);
            if (it != st.end()) {

                st.erase(it);
                count++;
            } else {

                st.insert(num);
            }
        }

        return count;
    }
};