class Solution {
public:
    int def(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i>=coins.size()) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int t=0;
        if(coins[i]<=amount){
            t=def(i,amount-coins[i],coins,dp);
        }
        int nt=def(i+1,amount,coins,dp);
        return dp[i][amount]=t+nt;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return def(0,amount,coins,dp);
    }
};