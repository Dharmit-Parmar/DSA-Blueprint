class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h{0}, maxH{0};

        for (const auto e : gain) {
            h += e;
            maxH = max(maxH, h);
        }

        return maxH;
    }
};