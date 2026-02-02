class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp=matrix[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int> temp=dp;
            for(int j=0;j<n;j++){
                int down=temp[j];
                int downLeft=(j>0) ? temp[j-1]:INT_MAX;
                int downRight=(j<n-1) ? temp[j+1]:INT_MAX;
                dp[j]=matrix[i][j]+min({down,downLeft,downRight});
            }
        }
        
        int res=INT_MAX;
        for(int n:dp){
            res=min(res,n);
        }
    return res;
    }
};