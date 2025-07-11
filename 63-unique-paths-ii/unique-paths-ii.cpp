class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1) return dp[i][j]=1;

        int right=dfs(i+1,j,grid,dp);
        int down=dfs(i,j+1,grid,dp);

        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp (obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return dfs(0,0,obstacleGrid,dp);
    }
};