class Solution {
public:
    /**
     * @brief Counts the number of special characters in a word.
     * @details A character is considered special if both its uppercase and
     *          lowercase versions appear anywhere in the string.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> Single pass traversal with O(1) average hash
     * set operations.
     * - Space Complexity: O(n) -> Uses two hash sets to keep track of
     * characters.
     */
    int numberOfSpecialChars(string word) {
        int count{0};
        unordered_set<char> s; // Stores characters we have seen
        unordered_set<char>
            counted; // Stores lowercase characters already counted

        for (const auto c : word) {
            if (isupper(c)) {
                char lower_c = tolower(c);
                // If we've seen the lowercase version, and haven't counted this
                // pair yet
                if (s.find(lower_c) != s.end() &&
                    counted.find(lower_c) == counted.end()) {
                    count++;
                    counted.insert(
                        lower_c); // Mark as counted so we don't count it again
                }
                s.insert(c); // Add current uppercase character to the seen set
            } else if (islower(c)) {
                char upper_c = toupper(c);
                // If we've seen the uppercase version, and haven't counted this
                // pair yet
                if (s.find(upper_c) != s.end() &&
                    counted.find(c) == counted.end()) {
                    count++;
                    counted.insert(
                        c); // Mark as counted so we don't count it again
                }
                s.insert(c); // Add current lowercase character to the seen set
            }
        }
        return count;
    }
};