class Solution {
public:
    int func(int i,int j,int c,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>& dp){

        if(i==grid.size() || j==grid[0].size() || c>k) return INT_MIN;
        int curCost=(grid[i][j]==0)? 0:1;
        if(i==grid.size()-1 && j==grid[0].size()-1) return (curCost+c<=k)? grid[i][j]:INT_MIN;
        if(dp[i][j][c]!=-1) return dp[i][j][c];
        int down=func(i+1,j,c+curCost,grid,k,dp);
        int right=func(i,j+1,c+curCost,grid,k,dp);
        if(down!=INT_MIN) down+=grid[i][j];
        if(right!=INT_MIN) right+=grid[i][j];
    return dp[i][j][c]=max(down,right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
       int res=func(0,0,0,grid,k,dp);
    return (res==INT_MIN)? -1:res;
    }
};