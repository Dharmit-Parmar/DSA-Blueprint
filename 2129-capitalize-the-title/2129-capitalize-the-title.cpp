#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief Capitalizes words in a title.
     * Logic:
     * - If length is 1 or 2: all letters are lowercase.
     * - If length > 2: first letter is uppercase, rest are lowercase.
     */
    string capitalizeTitle(string title) {
        int n = title.size();
        int i = 0; // Pointer to the start of the word

        while (i < n) {
            int j = i;
            // Find the end of the current word
            while (j < n && title[j] != ' ') {
                j++;
            }

            // Word length is (j - i)
            if (j - i <= 2) {
                // Convert whole word to lowercase
                for (int k = i; k < j; k++)
                    title[k] = tolower(title[k]);
            } else {
                // First letter uppercase, rest lowercase
                title[i] = toupper(title[i]);
                for (int k = i + 1; k < j; k++)
                    title[k] = tolower(title[k]);
            }

            // Move i to the start of the next word (skip the space)
            i = j + 1;
        }
        return title;
    }
};