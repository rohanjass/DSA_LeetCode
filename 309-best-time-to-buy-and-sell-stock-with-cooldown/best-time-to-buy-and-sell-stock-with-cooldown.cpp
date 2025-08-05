class Solution {
public:
    int dfs(int i,int buying,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buying]!=-1) return dp[i][buying];

        int coolDown=dfs(i+1,buying,prices,dp);
        if(buying){
            int buy=dfs(i+1,0,prices,dp)-prices[i];
            dp[i][buying]=max(buy,coolDown);
        } else {
            int sell=dfs(i+2,1,prices,dp)+prices[i];
            dp[i][buying]=max(sell,coolDown);
        }
    return dp[i][buying];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return dfs(0,1,prices,dp);
    }
};