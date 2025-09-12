class Solution {
public:
    int dfs(int i,int j,int& m,int& n,string& word1, string& word2,vector<vector<int>>& dp){
        if(i==m) return n-j;
        if(j==n) return m-i;

        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=dfs(i+1,j+1,m,n,word1,word2,dp);
        } 
        int op1=1+dfs(i+1,j,m,n,word1,word2,dp);
        int op2=1+dfs(i,j+1,m,n,word1,word2,dp);
        
    return dp[i][j]=min(op1,op2);
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return dfs(0,0,m,n,word1,word2,dp);
    }
};