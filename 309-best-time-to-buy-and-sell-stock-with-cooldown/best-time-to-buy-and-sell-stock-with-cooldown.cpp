class Solution {
public:
    int def(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int coolDown=def(i+1,buy,prices,dp);
        if(buy){
            int buyProfit=def(i+1,0,prices,dp)-prices[i];
            dp[i][buy]=max(coolDown,buyProfit);
        } else {
            int sell=def(i+2,1,prices,dp)+prices[i];
            dp[i][buy]=max(coolDown,sell);
        }
    return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return def(0,1,prices,dp);
    }
};