class Solution {
public:
    int def(int i,int j,string& s, string& t,vector<vector<int>>& dp){
        if(j==t.size()) return 1;
        if(i==s.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long res=0;
        if(s[i]==t[j]) res+=def(i+1,j+1,s,t,dp);
        res+=def(i+1,j,s,t,dp);

        return dp[i][j]=res;
    }
    int numDistinct(string s, string t) {
        int s1=s.size(),s2=t.size();
        vector<vector<int>> dp(s1,vector<int>(s2,-1));
        return def(0,0,s,t,dp);
    }
};