class Solution {
public:
    bool part(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==0) return false;
        if(dp[i][target]!=-1) return dp[i][target];

        bool notTake=part(i-1,target,nums,dp);
        bool take=false;
        if(nums[i]<=target){
            take=part(i-1,target-nums[i],nums,dp);
        }
    return dp[i][target]=notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(int n:nums){
            target+=n;
        }
        if(target%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>(target/2+1,-1));
        return part(n-1,target/2,nums,dp);
    }
};