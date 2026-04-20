class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int func(int i,int curSum,int tar,vector<int>& stones){
        if(i==n) return curSum;
        if(dp[i][curSum]!=-1) return dp[i][curSum];

        int skip=func(i+1,curSum,tar,stones);

        int take=curSum;
        if(curSum+stones[i]<=tar){
            take=func(i+1,curSum+stones[i],tar,stones);
        }
    return dp[i][curSum]=max(skip,take);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i:stones){
            sum+=i;
        }
        n=stones.size();
        int tar=sum/2;
        dp.resize(n,vector<int>(tar+1,-1));
        int res=func(0,0,tar,stones);
    return sum-2*res;
    }
};