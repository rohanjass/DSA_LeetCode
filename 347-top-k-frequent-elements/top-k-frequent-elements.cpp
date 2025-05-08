class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int> res;
        for(int n:nums){
            mp[n]++;
        }
        vector<pair<int,int>>arr;
        for(const auto& p:mp){
            arr.push_back({p.second,p.first});
        }
        sort(arr.rbegin(),arr.rend());

        for(int i=0;i<k;i++){
            res.push_back(arr[i].second);
        }
    return res;
    }
};