class Solution {
public:
    int dfs(int i,int j,const string& s,const  string& t,vector<vector<int>>& dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long res=0;
        if(s[i]==t[j]){
            res+=dfs(i+1,j+1,s,t,dp);
        }
        res+=dfs(i+1,j,s,t,dp);
    return dp[i][j]=res;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return dfs(0,0,s,t,dp);
    }
};