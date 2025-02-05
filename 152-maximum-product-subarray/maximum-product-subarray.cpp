class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int resMin=1,resMax=1;
        for(int num:nums){
            int temp=resMax*num;//resmax change hojaega same iteration me to resMin me galat resMax jayega
            resMax=max(max(resMax*num,num*resMin),num);
            resMin=min(min(temp,num*resMin),num);
            res=max(res,resMax);
        }
    return res;
    }
};