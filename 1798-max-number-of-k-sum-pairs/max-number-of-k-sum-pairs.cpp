class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int count=0;
        while(l<r){
            int curr_sum=nums[l]+nums[r];
            if(curr_sum==k){
                count++;
                l++;
                r--;
            } else if(curr_sum<k){
                l++;
            } else {
                r--;
            }
        }
    return count;
    }
};