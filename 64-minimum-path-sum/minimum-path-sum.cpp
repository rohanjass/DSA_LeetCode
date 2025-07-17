class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return INT_MAX;
        } 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return dp[i][j]=grid[i][j];
        }
        return dp[i][j]=grid[i][j]+min(dfs(grid,i+1,j,dp),dfs(grid,i,j+1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(grid,0,0,dp);
    }
};