class Solution {
public:
    int def(int i,bool buying,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buying]!=-1) return dp[i][buying];
        int cool=def(i+1,buying,prices,dp);
        int res=0;
        if(buying){
            res=max(cool,def(i+1,false,prices,dp)-prices[i]);
        } else {
            res=max(cool,def(i+1,true,prices,dp)+prices[i]);
        }
    return dp[i][buying]=res;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return  def(0,true,prices,dp);
    }
};