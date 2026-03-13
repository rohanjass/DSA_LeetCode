class Solution {
public:
    int func(int k,int n,vector<vector<int>>& dp){
        if(n==0 || n==1) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];

        int l=1,r=n;
        int ans=n;
        while(l<=r){
            int mid=(l+r)/2;

            int eggBreak=func(k-1,mid-1,dp);
            int notBreak=func(k,n-mid,dp);

            int temp=1+max(eggBreak,notBreak);
            ans=min(ans,temp);

            if(eggBreak>notBreak){
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
    return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return func(k,n,dp);
    }
};