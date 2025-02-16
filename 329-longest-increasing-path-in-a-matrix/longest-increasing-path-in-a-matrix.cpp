class Solution {
public:
    vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& matrix,int row,int col,int preVal){
        if(row<0 || col<0 || row>=matrix.size() || col>=matrix[0].size() || matrix[row][col]<=preVal) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int res=1;
        for(auto d:dirs){
            int nr=row+d[0];
            int nc=col+d[1];
            res=max(res,1+dfs(matrix,nr,nc,matrix[row][col]));
        }
        dp[row][col]=res;
    return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        dp=vector<vector<int>>(row,vector<int>(col,-1));
        int LIP=-1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                LIP=max(LIP,dfs(matrix,i,j,INT_MIN));
            }
        }
    return LIP;
    }
};