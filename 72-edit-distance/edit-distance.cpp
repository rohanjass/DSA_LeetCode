class Solution {
public:
    int dfs(int i,int j,string& word1, string& word2,vector<vector<int>>& dp){
        if(i==word1.size()) return word2.size()-j;//word1 is exhausted so to match now we need to insert all left out ch of word2
        if(j==word2.size()) return word1.size()-i;//word2 is exhausted so to match now we need to delete all left out ch of word1

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=dfs(i+1,j+1,word1,word2,dp);
        }
        int res=min(dfs(i+1,j,word1,word2,dp),dfs(i,j+1,word1,word2,dp));
        res=min(res,dfs(i+1,j+1,word1,word2,dp));
    return dp[i][j]=1+res;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return dfs(0,0,word1,word2,dp);
    }
};