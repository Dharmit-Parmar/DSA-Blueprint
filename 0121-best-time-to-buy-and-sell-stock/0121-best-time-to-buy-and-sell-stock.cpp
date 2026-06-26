class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // We start with the first price as our 'minimum'
        // and assume we haven't made any profit yet.

        int min_price{prices[0]};
        int max_profit{0};

        // We walk through the price list exactly once.
        // It's like watching the ticker tape go by.

        for (const int current_price : prices) {

            // Is today's price cheaper than any price we've seen before?
            // If yes, we update our 'buy' target.

            min_price = min(current_price, min_price);

            // If we sold at today's price, would we beat our current record?
            // We calculate the potential profit and keep the higher value.

            max_profit = max(max_profit, current_price - min_price);
        }

        return max_profit;
    }
};