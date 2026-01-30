class Solution {
public:
    bool pal(string& s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
    return true;
    }
    int def(int ind,int n,string& s,vector<int>& dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res=INT_MAX;
        for(int i=ind;i<n;i++){
            if(pal(s,ind,i)){
                res=min(res,1+def(i+1,n,s,dp));
            }
        }
    return dp[ind]=res;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return def(0,n,s,dp)-1;
    }
};