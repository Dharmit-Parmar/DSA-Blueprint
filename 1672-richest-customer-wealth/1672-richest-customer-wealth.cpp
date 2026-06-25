class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n =accounts[0].size() ;
        int richest_customer = 0 ;
        int sum = 0 ;
        for(auto i{0} ; i<m ;i++ )
        {
            sum = 0 ;
            for(auto j{0} ; j< n ; j++)
            {
                sum+= accounts[i][j];
            }

            richest_customer = max(richest_customer , sum);
        }

        return richest_customer ;
    }
};