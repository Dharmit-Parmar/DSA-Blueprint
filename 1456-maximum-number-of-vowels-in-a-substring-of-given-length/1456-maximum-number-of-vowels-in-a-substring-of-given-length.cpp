class Solution {
public:
    // Helper function is faster and uses less memory than unordered_set.
    // It directly compares ASCII values rather than computing hashes.
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    /**
     * METHODOLOGY: Fixed-Size Sliding Window
     * Calculate the first window of size k. Then, slide the window by adding
     * the new character on the right and subtracting the old character on the
     * left.
     *
     * Time Complexity: O(n) -> We visit each character exactly once.
     * Space Complexity: O(1) -> We only use a few integer variables.
     */
    int maxVowels(string s, int k) {
        int max_vowels = 0;
        int current_vowels = 0;

        // 1. Process the very first window of size k (indices 0 to k-1)
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
        }
        // Initialize max_vowels with the result of the first window
        max_vowels = current_vowels;

        // 2. Slide the window across the rest of the string, one character at a
        // time
        for (int i = k; i < s.size(); i++) {

            // Step A: Add the new character entering the window on the right
            // (index i)
            if (isVowel(s[i])) {
                current_vowels++;
            }

            // Step B: Remove the old character that just fell out on the left
            // (index i - k) If the character that left was a vowel, we must
            // subtract it from our current count.
            if (isVowel(s[i - k])) {
                current_vowels--;
            }

            // Step C: Check if this new window has more vowels than our
            // previous record
            max_vowels = max(max_vowels, current_vowels);
        }

        return max_vowels;
    }
};