#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief Calculates the minimum total price after applying available
     * percentage discounts.
     * @param prices Vector of item prices.
     * @param discounts Vector of percentage discount values (e.g., 20 means
     * 20%).
     * @return double The minimum final price after optimally pairing discounts.
     */
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        // Step 1: Sort both vectors in ascending order to easily access largest
        // elements at the end
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int i = prices.size() - 1;    // Pointer for most expensive prices
        int j = discounts.size() - 1; // Pointer for largest discounts

        double finalPrice = 0.0;

        // Step 2 & 3: Pair largest prices with largest discounts to maximize
        // savings
        while (i >= 0 && j >= 0) {
            double discounted = prices[i] * (1.0 - (discounts[j] / 100.0));
            finalPrice += discounted;
            i--;
            j--;
        }

        // Step 4: Add remaining items that didn't get a discount (no discounts
        // left)
        while (i >= 0) {
            finalPrice += prices[i];
            i--;
        }

        return finalPrice;
    }
};

/**
 * METHODOLOGY: Greedy Strategy (Rearrangement Inequality)
 * 1. To minimize the final total price, we need to maximize our total savings
 * (absolute discount amount).
 * 2. By sorting both prices and discounts in ascending order, we can pair the
 * **largest prices** with the **largest percentage discounts** from the back.
 * Applying a high percentage discount to a large price saves significantly more
 * money than applying it to a cheap item.
 * 3. Any leftover items without a corresponding discount are added at their
 * full price.
 *
 * COMPLEXITY ANALYSIS:
 * - Time Complexity: O(N log N + M log M), where N is the number of prices and
 * M is the number of discounts, due to sorting both vectors. The linear scan
 * takes O(N + M) time.
 * - Space Complexity: O(1) auxiliary space (ignoring sorting stack overhead).
 */