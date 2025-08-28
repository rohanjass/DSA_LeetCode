class Solution {
public:
    bool dfs(int i,int j,int k,string& s1, string& s2, string& s3,vector<vector<int>>& dp){
        if(k==s3.size()) return (i==s1.size()) && (j==s2.size());
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        if(i<s1.size() && s1[i]==s3[k]){
            res=dfs(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(!res && j<s2.size() && s2[j]==s3[k]){
            res=dfs(i,j+1,k+1,s1,s2,s3,dp);
        }
    return dp[i][j]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        if(m+n!=s3.size()) return false;
        return dfs(0,0,0,s1,s2,s3,dp);
    }
};