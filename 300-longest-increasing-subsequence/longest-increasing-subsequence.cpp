class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxLen=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(nums[i]<nums[j]) dp[i]=max(dp[i],1+dp[j]);
            }
            maxLen=max(maxLen,dp[i]);
        }
    return maxLen;
    }
};