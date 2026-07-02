class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
    int m,n;
    bool func(int i,int j,vector<vector<int>>& grid, int health,vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return false;
        if(grid[i][j]==-1) return false;
        if(grid[i][j]==1) health--;
        if(health<=0) return false;

        if(i==m-1 && j==n-1) return true;

        if(dp[i][j][health]!=-1) return dp[i][j][health];
        int temp=grid[i][j];
        grid[i][j]=-1;
        for(auto d:dir){
            int nr=i+d.first;
            int nc=j+d.second;
            if(func(nr,nc,grid,health,dp)){
                return dp[i][j][health]=1;
            }
        } 
        grid[i][j]=temp;
    return dp[i][j][health]=0;
    } 
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(health+1,-1)));
        return func(0,0,grid,health,dp);
    }
};