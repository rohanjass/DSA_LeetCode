class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int purchased=0;
        int res=money;
        sort(prices.begin(),prices.end());
        for(int p:prices){
            if(res-p<0 && purchased<2) return money;
            if(purchased<2){
                res=res-p;
                purchased++;
            }
        }
    return res;
    }
};