class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;

        sort(nums.begin(),nums.end());
        int minSum=INT_MAX;
        int l=0,r=k-1;
        while(r<nums.size()){
            minSum=min(minSum,nums[r]-nums[l]);
            l++;
            r++;
        }
    return minSum;
    }
};