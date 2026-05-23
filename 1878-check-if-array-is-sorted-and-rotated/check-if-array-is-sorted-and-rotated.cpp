class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                res++;
            }
        }
    return res<=1;
    }
};