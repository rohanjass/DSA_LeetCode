class Solution {
public:
    bool def(int i,int j,string& s, string& p,vector<vector<int>>& dp,int& m,int& n){
        if(i==m && j==n) return true;
        if(j==n) return false;
        if(i==m){
            for(int k=j;k<n;k++){
                if(p[k]!='*') return false;
            }
        return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        bool res=false;
        if(s[i]==p[j] || p[j]=='?'){
            res=def(i+1,j+1,s,p,dp,m,n);
        } else if( p[j]=='*'){
            res=def(i+1,j,s,p,dp,m,n) || def(i,j+1,s,p,dp,m,n);
        }
    return dp[i][j]=res;
    }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return def(0,0,s,p,dp,m,n);
    }
};