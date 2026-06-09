class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=0;
        int mini=INT_MAX;
        for(int n:nums){
            maxi=max(maxi,n);
            mini=min(mini,n);
        }
        long long res=(long long)(maxi-mini)*k;
    return res;
    }
};