class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int maxLen=0;
        for(int n:nums){
            if(!mp[n]){
                mp[n]=mp[n-1]+mp[n+1]+1;
                mp[n-mp[n-1]]=mp[n];
                mp[n+mp[n+1]]=mp[n];
            maxLen=max(maxLen,mp[n]);
            }
        }
    return maxLen;
    }
};