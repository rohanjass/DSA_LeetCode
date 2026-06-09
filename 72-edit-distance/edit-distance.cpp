class Solution {
public:
    int m,n;
    int func(int i,int j,string& word1,string& word2,vector<vector<int>>& dp){
        if(i==m) return n-j;
        if(j==n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=func(i+1,j+1,word1,word2,dp);
        }
        int op1=func(i+1,j,word1,word2,dp);
        int op2=func(i+1,j+1,word1,word2,dp);
        int op3=func(i,j+1,word1,word2,dp);
    return dp[i][j]=1+min({op1,op2,op3});
    }
    int minDistance(string word1, string word2) {
        m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
    return func(0,0,word1,word2,dp);
    }
};