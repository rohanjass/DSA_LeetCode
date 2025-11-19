class Solution {
public:
    int def(int i,vector<int>& cost,int res,vector<int>& dp){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int op1=def(i+1,cost,res+cost[i],dp);
        int op2=def(i+2,cost,res+cost[i],dp);

        return dp[i]=cost[i]+min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(def(0,cost,0,dp),def(1,cost,0,dp));
    }
};