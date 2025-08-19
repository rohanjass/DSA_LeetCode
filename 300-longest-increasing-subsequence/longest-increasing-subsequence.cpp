class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> dp(n,1);
        int res=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                res=max(res,dp[i]);
            }
        }
    return res;
    }
};