class Solution {
public:
    int def(int i,bool buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int coolDown=def(i+1,buy,prices,dp);

        if(buy){
            int brought=def(i+1,!buy,prices,dp)-prices[i];
            return dp[i][buy]=max(coolDown,brought);
        } else {
            int sell=def(i+2,true,prices,dp)+prices[i];
            return dp[i][buy]=max(coolDown,sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return def(0,true,prices,dp);
    }
};