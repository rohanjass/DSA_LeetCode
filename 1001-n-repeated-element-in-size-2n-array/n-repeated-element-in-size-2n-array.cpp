class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int target=n/2;
        for(int n:nums){
            if(mp.find(n)!=mp.end())mp[n]++;
            else mp[n]=1;
        }
        for(auto m:mp){
            if(m.second==target) return m.first;
        }
    return -1;
    }
};