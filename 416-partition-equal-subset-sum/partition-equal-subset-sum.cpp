class Solution {
public:
    bool def(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if (target < 0) return false; 
        if(i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool take=false;
        if(nums[i]<=target){
            take=def(i+1,target-nums[i],nums,dp);
        }
        int notTake=def(i+1,target,nums,dp);
        return dp[i][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return def(0,sum/2,nums,dp);
    }
};