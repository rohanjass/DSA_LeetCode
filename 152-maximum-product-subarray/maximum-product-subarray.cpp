class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int Max=1,Min=1;
        for(int num:nums){
            int temp=Max*num;
            Max=max(max(Max*num,Min*num),num);
            Min=min(min(temp,Min*num),num);
            res=max(res,Max);
        }
    return res;
    }
};