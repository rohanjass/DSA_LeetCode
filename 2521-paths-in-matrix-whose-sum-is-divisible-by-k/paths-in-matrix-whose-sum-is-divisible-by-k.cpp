class Solution {
public:
    int m,n;
    int MOD=1e9+7;
    int func(int i,int j,int sum,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>& dp){
        if(i>=m || j>=n) return 0;
        sum=(sum+grid[i][j])%k;

        if(i==m-1 && j==n-1) {
            if(sum==0) return 1;
        return 0;
        }

        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        int down=func(i+1,j,sum,grid,k,dp);
        int right=func(i,j+1,sum,grid,k,dp);
    return dp[i][j][sum]=(down+right)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return func(0,0,0,grid,k,dp);
    }
};