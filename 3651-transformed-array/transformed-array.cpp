class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int newInd=(i+nums[i])%n;
            if(newInd<0) newInd+=n;
            res[i]=nums[newInd];
        }
    return res;
    }

};