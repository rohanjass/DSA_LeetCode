class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int totalCount=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                    totalCount++;
                    dp[i][j]=true;
                }
            }
        }
    return totalCount;
    }
};