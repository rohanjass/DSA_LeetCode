class Solution {
public:
    int def(int i,int amount ,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(i>=coins.size()) return 1e8;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int t=1e8;
        if(coins[i]<=amount){
            t=1+def(i,amount-coins[i],coins,dp);
        }
        int nt=def(i+1,amount,coins,dp);
        return dp[i][amount]=min(t,nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int res=def(0,amount,coins,dp);
    return (res>=1e8)?-1:res;
    }
};