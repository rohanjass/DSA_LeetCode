class Solution {
public:
    int m,n;
    int func(int r,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(c1>=n || c2>=n || c1<0 || c2<0) return -1e9;
        if(r==m-1){
            if(c1==c2) return grid[r][c1];
        return grid[r][c1]+grid[r][c2];
        }
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int cherries=0;
        if(c1==c2) cherries+=grid[r][c1];
        else cherries+=grid[r][c1]+grid[r][c2];
        int best=0;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                best=max(best,func(r+1,c1+d1,c2+d2,grid,dp));
            }
        }
    return dp[r][c1][c2]=cherries+best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    return func(0,0,n-1,grid,dp);
    }
};