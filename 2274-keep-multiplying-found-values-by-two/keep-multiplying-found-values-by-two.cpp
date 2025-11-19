class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> mp;
        for(int n:nums){
            mp.insert(n);
        }
        int res=original;
        while(mp.find(res)!=mp.end()){
            res=2*res;
        }
    return res;
    }
};