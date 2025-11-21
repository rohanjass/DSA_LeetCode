class Solution {
public:
    int def(int i,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(i>=coins.size()){
           return 1e8;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=1e8;
        if(amount-coins[i]>=0){ 
            take=1+def(i,coins,amount-coins[i],dp);
        }
        int notTake=def(i+1,coins,amount,dp);

        return dp[i][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp (n+1,vector<int>(amount+1,-1));
        int res=def(0,coins,amount,dp);
        return (res>=1e8)? -1:res;
    }
};