class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int def(int i,int j,int preVal,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=preVal) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=1;
        for(auto d:dir){
            int nr=i+d.first;
            int nc=j+d.second;
            res=max(res,1+def(nr,nc,matrix[i][j],matrix,dp));
        }
    return dp[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int res=-1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,def(i,j,INT_MIN,matrix,dp));
            }
        }
    return res;
    }
};