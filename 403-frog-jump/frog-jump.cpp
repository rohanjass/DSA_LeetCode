class Solution {
public:
    bool def(int i,int k,vector<int>& stones,unordered_map<int,int>& stoneInd,vector<vector<int>>& dp){
        if(k<=0) return false;
        if(i==stones.size()-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        
        int res=false;

        if(stoneInd.count(stones[i]+k)){
            res=def(stoneInd[stones[i]+k],k,stones,stoneInd,dp);
        } 
        if(!res && stoneInd.count(stones[i]+k-1)){
            res=def(stoneInd[stones[i]+k-1],k-1,stones,stoneInd,dp);
        }
        if(!res && stoneInd.count(stones[i]+k+1)){
            res=def(stoneInd[stones[i]+k+1],k+1,stones,stoneInd,dp);
        }
    return dp[i][k]=res;
    }
    bool canCross (vector<int>& stones) {
        unordered_map<int,int> stoneInd;
        int n=stones.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            stoneInd[stones[i]]=i;
        }
        if(stones[1]!=1) return false;
    return def(1,1,stones,stoneInd,dp);
    }
};