class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(auto p:dp[i]){
                int sum=p.first,ways=p.second;
                dp[i+1][sum+nums[i]]+=ways;
                dp[i+1][sum-nums[i]]+=ways;
            }
        }
    return dp[n][target];
    }
};