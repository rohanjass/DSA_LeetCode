class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int> res;
        for(int n:nums){
            mp[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for(auto& i:mp){
            heap.push({i.second,i.first});
            if(heap.size()>k){
                heap.pop();
            }
        }

        for(int i=0;i<k;i++){
            res.push_back(heap.top().second);
            heap.pop();
        }
    return res;
    }
};