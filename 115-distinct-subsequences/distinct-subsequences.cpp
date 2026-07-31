class Solution {
public:
    int n,m;
    int func(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long res=0;
        if(s[i]==t[j]){
            res+=func(i+1,j+1,s,t,dp);
        }
        res+=func(i+1,j,s,t,dp);
    return dp[i][j]=res;
    }
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
    return func(0,0,s,t,dp);
    }
};