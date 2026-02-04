class Solution {
public:
    int maximizeProfit(int i,bool buying,vector<int>& prices, int fee,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buying]!=-1) return dp[i][buying];

        int skip=maximizeProfit(i+1,buying,prices,fee,dp);
        int res=1e9;
        if(buying){
            res=max(skip,maximizeProfit(i+1,false,prices,fee,dp)-prices[i]-fee);
        } else {
            res=max(skip,maximizeProfit(i+1,true,prices,fee,dp)+prices[i]);
        }
    return dp[i][buying]=res;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return maximizeProfit(0,true,prices,fee,dp);
    }
};