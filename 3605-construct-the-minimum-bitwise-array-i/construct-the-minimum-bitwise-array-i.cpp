class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int num:nums){
            int temp=num;
            int t=0;
            while((temp&1)==1){
                t++;
                temp>>=1;
            }
            if(t==0){
                res.push_back(-1);
            } else {
                int x=num-(1<<(t-1));
                res.push_back(x);
            }
        }
    return res;
    }
};