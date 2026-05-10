class Solution {
public:
    int func(int l,int r,vector<int>& nums,vector<vector<int>>& dp){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int res=0;
        for(int i=l;i<=r;i++){
            int cost=nums[l-1]*nums[i]*nums[r+1];
            res=max(res,cost+func(l,i-1,nums,dp)+func(i+1,r,nums,dp));
        }
    return dp[l][r]=res;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> newNums(n+2,1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        for(int i=0;i<n;i++){
            newNums[i+1]=nums[i];
        }
    return func(1,newNums.size()-2,newNums,dp);
    }
};