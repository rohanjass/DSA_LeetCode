class Solution {
public:
    bool def(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        int n=s.size();
        int m=p.size();
        if(i==n && j==m) return true;
        if(j==m) return false;
        if (i == n) {
            for (int k = j; k < m; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool res=false;
        if(s[i]==p[j] || p[j]=='?'){
            res=def(i+1,j+1,s,p,dp);
        } else if(p[j]=='*'){
            res= def(i+1,j,s,p,dp) || def(i,j+1,s,p,dp);
        }
    return dp[i][j]=res;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp (n,vector<int>(m,-1));
        return def(0,0,s,p,dp);
    }
};