class Solution {
public:
    int dfs(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+dfs(i+2,nums,dp);
        int notTake=dfs(i+1,nums,dp);

        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return dfs(0,nums,dp);
    }
};