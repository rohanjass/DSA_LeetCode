class Solution {
public:
    int dfs(int i,int amount, vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        if(i>=coins.size()) return 0;
        int opt1=dfs(i,amount-coins[i],coins,dp);
        int opt2=dfs(i+1,amount,coins,dp);
    return dp[i][amount]=opt1+opt2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return dfs(0,amount,coins,dp);
    }
};