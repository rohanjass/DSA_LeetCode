class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        int left=0;
        int right=sum;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            right-=nums[i];
            if(abs(left-right)%2==0) count++;
        }
    return count;
    }
};