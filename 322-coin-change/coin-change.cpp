class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i) dp[i]=min(dp[i],dp[i-coins[j]]+1);
                //dp[i-coins[j]]+1---> taking current( +1 ) coin and looking back to find balance amount( dp[i-coins[j]] );
            }
        }
    return dp[amount]>amount? -1:dp[amount];
    //we intialized evryone to amount+1 so id fp[amount]>amount that means no combination is founded!!
    }
};