class Solution {
public:
    
    int climbStairs(int n) {
        if(n<=1) return 1;
        vector<int> dp(n+1);
        dp[n]=1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1]+dp[i+2];
        }
    return dp[0];
    }
};