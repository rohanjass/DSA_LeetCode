class Solution {
public:
    int def(int i,int j,string& s1, string& s2,vector<vector<int>>& dp){
        if(i==s1.size() || j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+def(i+1,j+1,s1,s2,dp);
        }
        else{
           return dp[i][j]=max(def(i+1,j,s1,s2,dp),def(i,j+1,s1,s2,dp));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return def(0,0,text1,text2,dp);
    }
};