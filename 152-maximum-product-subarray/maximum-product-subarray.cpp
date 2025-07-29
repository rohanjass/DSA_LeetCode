class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int currMin=1,currMax=1;
        for(int num:nums){
            int temp=currMax*num;
            currMax=max(max(currMax*num,currMin*num),num);
            currMin=min(min(temp,currMin*num),num);
            res=max(currMax,res);
        }
    return res;
    }
};