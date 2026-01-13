class Solution {
public:
    int def(int i,int j,string& word1, string& word2,vector<vector<int>>& dp,int m,int n){
        if(i==m) return n-j;//insert left part into s1
        if(j==n) return m-i;//deleting part left in st1

        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=def(i+1,j+1,word1,word2,dp,m,n);
        }
        int op1=def(i,j+1,word1,word2,dp,m,n);
        int op2=def(i+1,j,word1,word2,dp,m,n);
        int op3=def(i+1,j+1,word1,word2,dp,m,n);
    return dp[i][j]=1+min({op1,op2,op3});
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp (m,vector<int>(n,-1));
        return def(0,0,word1,word2,dp,m,n);
    }
};