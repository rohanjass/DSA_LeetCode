class Solution {
public:
    int dfs(vector<int>& nums,int i,bool flag,vector<vector<int>>& dp){
        if(i==nums.size()) return flag? 0:-1e6;
        int f=flag? 1:0;
        if(dp[i][f]!=INT_MIN) return dp[i][f];
        if(flag) 
            dp[i][f]= max(0,nums[i]+dfs(nums,i+1,true,dp));
        else
            dp[i][f]=max(dfs(nums,i+1,false,dp),nums[i]+dfs(nums,i+1,true,dp));
    return dp[i][f];
    }
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(2,INT_MIN));
        return dfs(nums,0,false,dp);
    }
};