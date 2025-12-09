class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long MOD=1e9+7;
        unordered_map<long,long> left,right;

        for(long x:nums) right[x]++;

        int ans=0;
        for(int j=0;j<nums.size();j++){
            long mid=nums[j];
            right[mid]--;

            long need=mid*2;

            ans=(ans+(left[need]*right[need]))%MOD;
            
            left[mid]++;
        }
    return ans;
    }
};