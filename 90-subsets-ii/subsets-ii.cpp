class Solution {
public:
    void func(int ind,vector<int>& nums,vector<int>& path,vector<vector<int>>& res){
        res.push_back(path);

        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            func(i+1,nums,path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(),nums.end());
        func(0,nums,path,res);
    return res;
    }
};