class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        int maxInd=0;
        int jumps=0;
        for(int i=0;i<n;i++){
            maxInd=max(maxInd,i+nums[i]);
            nums[i]=maxInd;
        }
        int i=0;
        while(i<n-1){
            i=nums[i];
            jumps++;
        }
    return jumps;
    }
};