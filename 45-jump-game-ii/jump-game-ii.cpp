class Solution {
public:
    int jump(vector<int>& nums) {
        int maxInd=0;
        int jump=0;
        for(int i=0;i<nums.size();i++){
            maxInd=max(maxInd,i+nums[i]);
            nums[i]=maxInd;
        }
        int i=0;
        while(i<nums.size()-1){
            i=nums[i];
            jump++;
        }
    return jump;
    }
};