class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        while(n>0){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    int temp=nums[i+1];
                    nums[i+1]=nums[i];
                    nums[i]=temp;
                }
            }
        n--;
        }
    return;
    }
};