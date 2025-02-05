class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[s.size()]=true;
        for(int i=s.size()-1;i>=0;i--){
            for(const auto& word:wordDict){
                if((i+word.size())<=s.size() && s.substr(i,word.size())==word){
                    dp[i]=dp[i+word.size()];
                    //ye true tabhi hoga jab uske exctly age wala bhi true ho
                    //if leet is valid than code should be valid too
                }
            if(dp[i]) break;
            }
        }
    return dp[0];
    }
};