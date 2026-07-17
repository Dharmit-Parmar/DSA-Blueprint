#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @brief Assigns the maximum number of cookies to children to satisfy their greed.
     * 
     * METHODOLOGY: Greedy Strategy
     * 1. Sort both the greed factors (g) and cookie sizes (s).
     * 2. Iterate through both arrays with pointers. 
     * 3. If a cookie is large enough to satisfy the current child, assign it 
     *    (move both child and cookie pointers).
     * 4. If the cookie is too small, move to the next larger cookie (cookie pointer 
     *    only) to try and satisfy the same child.
     * 
     * COMPLEXITY:
     * - Time: O(N log N + M log M) due to sorting (N=children, M=cookies).
     * - Space: O(1) if sorting is done in-place.
     */
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // Sort both greed factors and cookie sizes
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int childPtr = 0;
        int cookiePtr = 0;
        
        // Loop until we run out of children or cookies
        while (childPtr < g.size() && cookiePtr < s.size()) {
            // If the cookie satisfies the current child's greed
            if (s[cookiePtr] >= g[childPtr]) {
                childPtr++; // Move to the next child
            }
            // Move to the next cookie regardless
            // If satisfied, we've used this cookie.
            // If not, this cookie is too small for this child (and any greedier child), so discard it.
            cookiePtr++; 
        }
        
        // The value of childPtr is the total count of satisfied children
        return childPtr; 
    }
};