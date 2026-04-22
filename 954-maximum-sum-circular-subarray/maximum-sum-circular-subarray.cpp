class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax=0,maxSum=nums[0];
        int curMin=0,minSum=nums[0];
        int total=0;
        for(int n:nums){
            total+=n;
            curMax=max(n,curMax+n);
            curMin=min(n,curMin+n);

            maxSum=max(maxSum,curMax);
            minSum=min(minSum,curMin);
        }
        if(maxSum<0) return maxSum;
    return max(maxSum,total-minSum);
    }
};