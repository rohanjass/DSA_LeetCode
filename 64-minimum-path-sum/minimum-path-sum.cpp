class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return dp[i][j]=grid[i][j];
        }
        return dp[i][j]=grid[i][j]+min(dfs(i+1,j,grid,dp),dfs(i,j+1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(0, 0, grid,dp);
        
    }
};