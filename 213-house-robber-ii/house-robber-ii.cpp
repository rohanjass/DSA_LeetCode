class Solution {
public:
    int dfs(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>n) return 0;

        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+dfs(i+2,n,nums,dp);
        int notTake=dfs(i+1,n,nums,dp);

        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);

        int op1=dfs(0,n-2,nums,dp1);
        int op2=dfs(1,n-1,nums,dp2);
    return max(op1,op2);
    }
};