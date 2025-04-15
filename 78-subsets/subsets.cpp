class Solution {
public:
    void dfs(int i,vector<int>& nums,vector<int>& path,vector<vector<int>>& res){
        if(i==nums.size()){
            res.push_back(path);
            return;
        }

        path.push_back(nums[i]);
        dfs(i+1,nums,path,res);
        path.pop_back();
        dfs(i+1,nums,path,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0,nums,path,res);
    return res;
    }
};