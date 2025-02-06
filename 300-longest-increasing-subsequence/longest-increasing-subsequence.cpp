class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();

        if(n==0) return 0;
        int res=1;
        vector<int> LIS(n,1);
        LIS[n-1]=1;//base condn
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    LIS[i]=max(LIS[i],1+LIS[j]);
                }
            }
            res=max(res,LIS[i]);
        }
    return res;
    }
};