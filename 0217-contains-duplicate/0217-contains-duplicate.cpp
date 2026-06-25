class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;

        for (const auto e : nums) {
            if (s.find(e) != s.end()) {
                return true;
            }
            s.insert(e);
        }
        return false ;
    }
};