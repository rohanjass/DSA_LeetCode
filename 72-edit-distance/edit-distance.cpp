class Solution {
public:
    int dfs(int i,int j,string& word1, string& word2,vector<vector<int>>& dp,int m,int n){
        if(i==m) return n-j;
        if(j==n) return m-i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=dfs(i+1,j+1,word1,word2,dp,m,n);
        } 
        
        int res=min(dfs(i+1,j,word1,word2,dp,m,n),dfs(i,j+1,word1,word2,dp,m,n));
        res=min(res,dfs(i+1,j+1,word1,word2,dp,m,n));

    return dp[i][j]=1+res;
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return dfs(0,0,word1,word2,dp,m,n);
    }
};