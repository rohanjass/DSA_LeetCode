class Solution {
public:
    int n;
    
    int func(int i,vector<int>& nums,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int take=0;
        int best=INT_MIN;
        for(int k=0;k<3 && i+k<n;k++){
            take+=nums[i+k];
            best=max(best,take-func(i+k+1,nums,dp));
        }
    return dp[i]=best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int> dp(n,-1);
        int res=func(0,stoneValue,dp);
        if(res<0) return "Bob";
        else if(res>0) return "Alice";
        else return "Tie";
    }
};