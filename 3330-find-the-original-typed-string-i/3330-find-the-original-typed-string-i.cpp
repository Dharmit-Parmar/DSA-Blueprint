class Solution {
public:
    /**
     * @brief Finds the total number of possible original strings Alice might
     * have intended to type, given that she could have pressed a key for too
     * long at most once.
     *
     * METHODOLOGY:
     * Every group of consecutive identical characters represents a location
     * where Alice could have accidentally held down a key. For a group of
     * identical characters of length `L`, there are `L - 1` ways to shorten it.
     * Summing `L - 1` across all consecutive groups—plus 1 for the original
     * string itself—gives the total variations. This simplifies to counting how
     * many times adjacent characters are identical, plus 1.
     *
     * COMPLEXITY:
     * - Time Complexity: O(n), where n is the length of the string, since we
     * traverse it once.
     * - Space Complexity: O(1), as we only use a counter variable.
     */
    int possibleStringCount(string word) {
        // Initialize the count to 1 to account for the original, unmodified
        // string
        int possibleCount = 1;

        // Iterate through the string starting from index 1 to check adjacent
        // pairs
        for (int i = 1; i < word.size(); ++i) {
            // If the current character matches the previous one, it forms or
            // extends a group of consecutive duplicates, increasing our total
            // possible variations by 1.
            if (word[i] == word[i - 1]) {
                possibleCount++;
            }
        }

        return possibleCount;
    }
};