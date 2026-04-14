class Solution {
public:
    long long func(int i,int j,vector<int>& robot, vector<vector<int>>& factory,int n,int m,vector<vector<long long>>& dp){
        if(i==n) return 0;
        if(j==m) return 1e15;
        if(dp[i][j]!=-1) return dp[i][j];

        long long res=func(i,j+1,robot,factory,n,m,dp);

        long long cost=0;
        int pos=factory[j][0];
        int limit=factory[j][1];

        for(int k=0;k<limit && i+k<n;k++){
            cost+=abs(robot[i+k]-pos);
            res=min(res,cost+func(i+k+1,j+1,robot,factory,n,m,dp));
        }
    return dp[i][j]=res;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int n=robot.size();
        int m=factory.size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));

    return func(0,0,robot,factory,n,m,dp);
    }
};