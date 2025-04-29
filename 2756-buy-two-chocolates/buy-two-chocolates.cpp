class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int purchased=0;
        int res=0;
        sort(prices.begin(),prices.end());
        res=prices[0]+prices[1];
        if(res>money) return money;
    return money-res;
    }
};