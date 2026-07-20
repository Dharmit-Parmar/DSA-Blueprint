class Solution {
public:
    /**
     * @brief Counts how many integers in the array have an even number of
     * digits.
     *
     * METHODOLOGY:
     * For each integer, we extract its total digits by repeatedly dividing by
     * 10 until the number becomes zero. If the total digit count is divisible
     * by 2, we increment our result counter.
     *
     * COMPLEXITY:
     * - Time Complexity: O(n * d), where n is the number of elements and
     *   d is the average number of digits per element.
     * - Space Complexity: O(1).
     */
    int findNumbers(vector<int>& nums) {
        int even_number_element{0};

        // Access each element in the input vector
        for (const auto e : nums) {
            int element{e};
            int count{0};

            // Calculate the number of digits in the current integer
            while (element != 0) {
                element /= 10;
                count++;
            }

            // Check if the number of digits is even
            // Note: If input includes 0, count will be 0 (even),
            // but typical problem constraints often start from 1.
            if (count % 2 == 0 && count != 0) {
                even_number_element++;
            }
        }

        return even_number_element;
    }
};