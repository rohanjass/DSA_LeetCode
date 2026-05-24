class Solution {
public:
    int func(int i,int d,vector<int>& arr,vector<int>& dp){
        if(dp[i]!=-1) return dp[i];
        int res=1;
        for(int j=i+1;j<=i+d;j++){
            if(j>=arr.size()) break;
            if(arr[j]>=arr[i]) break;
            res=max(res,1+func(j,d,arr,dp));
        }
        for(int j=i-1;j>=i-d;j--){
            if(j<0) break;
            if(arr[j]>=arr[i]) break;
            res=max(res,1+func(j,d,arr,dp));
        }
    return dp[i]=res;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n,-1);
        int res=1;
        for(int i=0;i<n;i++){
            res=max(res,func(i,d,arr,dp));
        }
    return res;
    }
};