class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;

        // finding the max area using 2 pointer
        int max_area = 0;
        while (left < right) {

            // updating max area every time 
            max_area = max((right - left) * (min(height[right], height[left])),
                           max_area);
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else {
                right--;
                left++;
            }
        }

        return max_area;
    }
};