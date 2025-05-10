class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int res=nums[0];
       int resMax=1,resMin=1;
       for(int num:nums){
        int temp=resMax*num;
        resMax=max(max(resMax*num,resMin*num),num);
        resMin=min(min(temp,resMin*num),num);
        res=max(res,resMax);
       }
    return res;
    }
};