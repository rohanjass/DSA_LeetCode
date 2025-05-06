class Solution {
public:
    string longestPalindrome(string s) {
        int resLen=0;
        int resInd=-1;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(resLen<(j-i+1)){
                        resLen=j-i+1;
                        resInd=i;
                    }
                }
            }
        }
    return s.substr(resInd,resLen);

    }
};