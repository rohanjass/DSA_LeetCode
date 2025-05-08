class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1);
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            } else {
                dp[i]=dp[i+1];//taking one element 
                if(i+1<s.size() &&(s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
                    dp[i]+=dp[i+2];//taking two elements
                }
            }
        }
    return dp[0];
    }
};