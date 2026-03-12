class Solution {
public:
    int func(int i,int j,string& s,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        if(s[i]==s[j]){
            res=2+func(i+1,j-1,s,dp);
        }
        else res=max(func(i+1,j,s,dp),func(i,j-1,s,dp));
    return dp[i][j]=res;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0,n-1,s,dp);
    }
};