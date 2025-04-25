class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1,missing=-1;
        for(int i=0;i<nums.size();i++){
            int ind=abs(nums[i])-1;
            if(nums[ind]<0){
                dup=abs(nums[i]);
            } else{
                nums[ind]=-(nums[ind]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) missing=i+1;
        }
    return {dup,missing};
    }
};