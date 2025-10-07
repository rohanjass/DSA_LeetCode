class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int Max=1,Min=1;
        for(int num:nums){
            int temp=num*Max;
            Max=max(num,max(num*Max,num*Min));
            Min=min(num,min(temp,num*Min));

        res=max(res,Max);
        }
    return res;
    }
};