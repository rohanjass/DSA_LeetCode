class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res=0,tarIndBac=INT_MAX,tarIndFor=INT_MAX;
        int n=nums.size();
        for(int i=start;i<n;i++){
            if(nums[i]==target){
                tarIndFor=i;
                break;
            }
        }
        for(int i=start;i>=0;i--){
            if(nums[i]==target){
                tarIndBac=i;
                break;
            }
        }
        res=min(abs(tarIndFor-start),abs(tarIndBac-start));
    return res;
    }
};