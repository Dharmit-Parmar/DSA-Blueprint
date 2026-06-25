class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max_wealth{0};

        // Iterate through each customer's account row
        for (const auto& customer : accounts) {
            
            // Calculate sum of current row using accumulate (the minimal way to sum)
            int current_sum = accumulate(customer.begin(), customer.end(), 0);
            
            // Update the maximum found so far
            max_wealth = max(max_wealth, current_sum);
        }

        return max_wealth;
    }
};