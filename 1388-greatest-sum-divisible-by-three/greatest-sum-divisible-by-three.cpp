class Solution {
public:
    int def(int i,vector<int>& nums,int sum,vector<vector<int>>& dp){
        if(i==nums.size()){
            if(sum==0){
                return 0;
            } else {
                return INT_MIN;
            }
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int op1=nums[i]+def(i+1,nums,(sum+nums[i])%3,dp);
        int op2=def(i+1,nums,sum,dp);
        return dp[i][sum]=max(op1,op2);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return def(0,nums,0,dp);
    }
};