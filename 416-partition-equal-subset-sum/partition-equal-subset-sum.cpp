class Solution {
public:
    bool func(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        bool notTake=func(i+1,target,nums,dp);
        bool take=false;
        if(target-nums[i]>=0){
            take=func(i+1,target-nums[i],nums,dp);
        }
    return dp[i][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0) return false;
        int target=total/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

    return func(0,target,nums,dp);
    }
};