class Solution {
public:
    bool def(int i,int k,vector<int>& arr,unordered_map<int,int>& mp,vector<vector<int>>& dp){
        if(k<=0) return false;
        if(i==arr.size()-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        int res=false;
        if(mp.count(arr[i]+k)){
            res= def(mp[arr[i]+k],k,arr,mp,dp);
        }
        if(!res && mp.count(arr[i]+k-1)){
            res= def(mp[arr[i]+k-1],k-1,arr,mp,dp);
        }
        if(!res && mp.count(arr[i]+k+1)){
            res= def(mp[arr[i]+k+1],k+1,arr,mp,dp);
        }
    return dp[i][k]=res;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> mp;
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        if(stones[1]!=1) return false;
    return def(1,1,stones,mp,dp);
    }
};