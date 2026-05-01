class Solution {
public:
    int func(int i,int diff,vector<int>& rods,vector<vector<int>>& dp){
        if(i==rods.size()){
            return (diff==0)? 0:-1e9;
        }
        if(dp[i][diff]!=-1) return dp[i][diff];
        int x=rods[i];
        int res=func(i+1,diff,rods,dp);
        res=max(res,func(i+1,diff+x,rods,dp));

        int newDiff=abs(diff-x);
        int gain=min(diff,x);

        res=max(res,gain+func(i+1,newDiff,rods,dp));
    return dp[i][diff]=res;
    }
    int tallestBillboard(vector<int>& rods) {
        int sum=accumulate(rods.begin(),rods.end(),0);
        int n=rods.size();
        vector<vector<int>> dp(n,vector<int>(sum,-1));
        return func(0,0,rods,dp);
    }
};