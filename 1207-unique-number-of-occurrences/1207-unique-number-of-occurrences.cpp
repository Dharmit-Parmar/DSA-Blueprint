#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> h;

        // Step 1: Count frequencies
        for (int num : arr) {
            h[num]++;
        }

        unordered_set<int> seenFrequencies;

        for (const auto& pair : h) {
            int freq = pair.second;

            if (seenFrequencies.count(freq)) {
                return false;
            }

            seenFrequencies.insert(freq);
        }

        return true;
    }
};