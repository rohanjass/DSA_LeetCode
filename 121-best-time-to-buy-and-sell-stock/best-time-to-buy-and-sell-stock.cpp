class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1;
        int maxProfit=0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit=prices[r]-prices[l];
                maxProfit=max(profit,maxProfit);
            } else {
                l=r;
            }
            r++;
        }
    return maxProfit;
    }
};