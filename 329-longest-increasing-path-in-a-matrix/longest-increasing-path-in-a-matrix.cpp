class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix,int r,int c,int preVal){
        if(r<0 || c<0 || r>=matrix.size() || c>=matrix[0].size() || matrix[r][c]<=preVal) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int  res=1;
        for(const auto& d:dir){
            int nr=r+d.first;
            int nc=c+d.second;
            res=max(res,1+dfs(matrix,nr,nc,matrix[r][c]));
        }
    return dp[r][c]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        dp=vector<vector<int>> (row,vector<int>(col,-1));
        int res=-1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res=max(res,dfs(matrix,i,j,INT_MIN));
            }
        }
    return res;
    }
};