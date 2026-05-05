class Solution {
public:
    int func(int i,bool buying,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buying]!=-1) return dp[i][buying];

        int cooldown=func(i+1,buying,prices,dp);
        if(buying){
            int buy=func(i+1,false,prices,dp)-prices[i];
        return dp[i][buying]=max(cooldown,buy);
        } else{
            int sell=prices[i]+func(i+2,true,prices,dp);
        return dp[i][buying]=max(cooldown,sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
    return func(0,true,prices,dp);
    }
};