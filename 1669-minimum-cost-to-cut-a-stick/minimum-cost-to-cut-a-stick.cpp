class Solution {
public:
    int dfs(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(j-i==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;

        for(int k=i+1;k<j;k++){
            res=min(res,cuts[j]-cuts[i]+dfs(i,k,cuts,dp)+dfs(k,j,cuts,dp));
        }
        return dp[i][j]=(res==INT_MAX)? 0:res;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return dfs(0,m-1,cuts,dp);
    }
};