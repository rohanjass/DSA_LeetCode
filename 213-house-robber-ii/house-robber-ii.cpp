class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>nums1(nums.begin()+1,nums.end());
        vector<int>nums2(nums.begin(),nums.end()-1);
        return max(nums[0],max(helper(nums1),helper(nums2)));
    }
    int helper(vector<int>& nums){
        int rob1=0,rob2=0;
        for(int rob:nums){
            int temp=max(rob+rob1,rob2);
            rob1=rob2;
            rob2=temp;
        }
    return max(rob1,rob2);
    }
};