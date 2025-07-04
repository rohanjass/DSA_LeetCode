class Solution {
public:
    void dfs(int i,vector<int>& nums,vector<vector<int>>& res,vector<int>& path){
        if(i==nums.size()){
            res.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        dfs(i+1,nums,res,path);
        path.pop_back();
        dfs(i+1,nums,res,path);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(0,nums,res,path);
        return res;
    }
};