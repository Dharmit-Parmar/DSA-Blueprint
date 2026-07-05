#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief Determines if the usage of capitals in a word is correct.
     * @details The logic covers three valid cases:
     *          1. All letters are capital (e.g., "USA")
     *          2. All letters are lowercase (e.g., "leetcode")
     *          3. Only the first letter is capital (e.g., "Google")
     */
    bool detectCapitalUse(string word) {
        // Create copies to compare against the original input
        string all_lower = word;
        string all_upper = word;

        // Transform the copies to specific cases
        transform(all_lower.begin(), all_lower.end(), all_lower.begin(),
                  ::tolower);
        transform(all_upper.begin(), all_upper.end(), all_upper.begin(),
                  ::toupper);

        // Case 1 & 2: If the word is entirely uppercase or lowercase, it's
        // valid.
        if (word == all_lower || word == all_upper) {
            return true;
        }

        // Case 3: Check for Title Case (e.g., "Google").
        // We verify the first character is uppercase, and the substring
        // from index 1 to the end matches the all-lowercase version.
        if (isupper(word[0]) && word.substr(1) == all_lower.substr(1)) {
            return true;
        }

        // If none of the conditions are met, the capitalization is incorrect.
        return false;
    }
};