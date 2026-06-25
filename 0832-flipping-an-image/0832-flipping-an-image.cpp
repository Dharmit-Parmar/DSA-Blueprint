class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for (auto& row : image) {
            // 1. Use two pointers to flip and invert simultaneously
            int left{0}, right{n - 1};

            while (left <= right) {
                // If pointers are at the same spot, just invert the bit
                if (left == right) {
                    row[left] ^= 1;
                } else {
                    // Swap AND invert both bits at once
                    // (val ^ 1) flips 0 to 1 and 1 to 0
                    int temp = row[left] ^ 1;
                    row[left] = row[right] ^ 1;
                    row[right] = temp;
                }
                left++;
                right--;
            }
        }
        return image;
    }
};