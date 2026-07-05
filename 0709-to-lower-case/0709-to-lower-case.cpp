class Solution {
public:
    /**
     * @brief Converts all uppercase characters in a string to lowercase.
     *
     * METHODOLOGY: ASCII Manipulation
     * In the ASCII table, uppercase 'A'-'Z' (65-90) and lowercase 'a'-'z'
     * (97-122) are separated by a constant offset of 32. By adding 32 to an
     * uppercase character, we shift it to its lowercase equivalent.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> We traverse the string once.
     * - Space Complexity: O(1) -> Performed in-place (if we ignore the input
     * string itself).
     */
    string toLowerCase(string s) {
        int n = s.size();

        for (int i{0}; i < n; i++) {
            // Check if the character falls within the uppercase ASCII range
            if (s[i] >= 'A' && s[i] <= 'Z') {
                // Shift to lowercase using the ASCII offset of 32
                s[i] = s[i] + 32;
            }
        }

        return s;
    }
};