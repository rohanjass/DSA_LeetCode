class Solution {
public:
    int def(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>& dp){
        int m=dungeon.size();
        int n=dungeon[0].size();

        if(i>=m || j>=n) return 1e9;
        if(i==m-1 && j==n-1) return max(1,1-dungeon[i][j]);

        if(dp[i][j]!=-1) return dp[i][j];

        int right=def(i,j+1,dungeon,dp);
        int down=def(i+1,j,dungeon,dp);

        int need=min(right,down)-dungeon[i][j];
        return dp[i][j]=max(1,need);

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(),vector<int>(dungeon[0].size(),-1));
        return def(0,0,dungeon,dp);
    }
};