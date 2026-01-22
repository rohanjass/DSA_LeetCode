class Solution {
public:
    int def(vector<int>& nums, int k){
        int l=0,count=0;
        unordered_map<int,int> mp;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
        count+=(r-l+1);
        }
    return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res1=def(nums,k);
        int res2=def(nums,k-1);
        return res1-res2;
    }
};