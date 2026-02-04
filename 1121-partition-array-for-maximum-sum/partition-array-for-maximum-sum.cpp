class Solution {
public:
    int def(int ind,vector<int>& arr, int k,vector<int>& dp){
        if(ind>=arr.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res=0;
        int maxSum=0;
        for(int i=ind;i<ind+k && i<arr.size();i++){
            maxSum=max(maxSum,arr[i]);
            int len=i-ind+1;
            res=max(res,def(i+1,arr,k,dp)+(len*maxSum));
        }
    return dp[ind]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return def(0,arr,k,dp);
    }
};