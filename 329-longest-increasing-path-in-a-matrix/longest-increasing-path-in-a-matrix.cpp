class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
    int findLongestPath(int i,int j,int pre,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || j<0 || i==m || j==n || matrix[i][j]<=pre) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        for(auto& d:dir){
            int r=i+d.first;
            int c=j+d.second;
            res=max(res,1+findLongestPath(r,c,matrix[i][j],matrix,dp));
        }
    return dp[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>>dp (m,vector<int>(n,-1));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,findLongestPath(i,j,INT_MIN,matrix,dp));
            }
        }
    return res;
    }
};