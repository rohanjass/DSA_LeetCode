class Solution {
public:
    int dfs(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return dp[i][j]=1;
        int right=dfs(i+1,j,m,n,dp);
        int down=dfs(i,j+1,m,n,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp (m,vector<int>(n,-1));
        return dfs(0,0,m,n,dp);
    }
};