class Solution {
public:
    int dfs(int i,int amount, vector<int>& coins ,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(dp[amount][i]!=-1) return dp[amount][i];
        if(i>=coins.size()) return 0;
        int op1=dfs(i,amount-coins[i],coins,dp);
        int op2=dfs(i+1,amount,coins,dp);

        return dp[amount][i]=op1+op2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        return dfs(0,amount,coins,dp);
    }
};