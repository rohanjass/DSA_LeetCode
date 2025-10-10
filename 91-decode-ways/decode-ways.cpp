class Solution {
public:
    int def(int i,string& s,vector<int>& dp){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int res=def(i+1,s,dp);
        if(i+1<s.size() && (s[i]=='1' || ( s[i]=='2' && s[i+1]<'7'))){
            res+=def(i+2,s,dp);
        }
    return dp[i]=res;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return def(0,s,dp);
    }
};