class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        int oddInd=1,evenInd=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res[evenInd]=nums[i];
                evenInd+=2;
            } else {
                res[oddInd]=nums[i];
                oddInd+=2;
            }
        }
    return res;
    }
};