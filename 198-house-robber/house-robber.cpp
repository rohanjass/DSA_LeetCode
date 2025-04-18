class Solution {
public:
    int dfs(int n,vector<int>& nums,vector<int>& dp){
        if(n==0){
            return nums[0];
        }
        if(n==1) return max(nums[1],nums[0]);
        if(dp[n]!=-1) return dp[n];
        int rob1=dfs(n-1,nums,dp);
        int rob2=dfs(n-2,nums,dp)+nums[n];
        dp[n]=max(rob1,rob2);
    return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        return dfs(n,nums,dp);
    }
};