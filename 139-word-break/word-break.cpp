class Solution {
public:
    bool dfs(int i,string s, vector<string>& wordDict, vector<int>& dp){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        for(const string& w:wordDict){
            if(i+w.size() <= s.size() && s.substr(i,w.size())==w){
                if(dfs(i+w.size(),s,wordDict,dp)){
                    return dp[i]=true;
                }
            }
        }
    return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return dfs(0,s,wordDict,dp);
    }
};