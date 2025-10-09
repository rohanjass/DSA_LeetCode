class Solution {
public:
    int def(int i,int j,string& s,vector<vector<int>>& dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return def(i+1,j-1,s,dp);
        } else {
            return 1+min(def(i+1,j,s,dp),def(i,j-1,s,dp));
        }
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                } else {
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
    return dp[0][n-1];
    }
};