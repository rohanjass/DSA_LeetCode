class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ind=0;
        for(int num : nums){
            if(num!=val){
                nums[ind]=num;
                ind++;
            } 
        }
        return ind;
    }
};