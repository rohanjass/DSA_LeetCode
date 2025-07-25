class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int n:nums){
            if(set.contains(n)) return true;
            set.insert(n);
        }
    return false;
    }
};