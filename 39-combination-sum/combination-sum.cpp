class Solution {
public:
    void dfs(int i,vector<int>& arr, int target,vector<int>& path,vector<vector<int>>& res){
        if(i>=arr.size()){
            if(target==0){
                res.push_back(path);
            }
            return;
        }
        if(arr[i]<=target){
            path.push_back(arr[i]);
            dfs(i,arr,target-arr[i],path,res);
            path.pop_back();
        }
        dfs(i+1,arr,target,path,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0,candidates,target,path,res);
        return res;
    }
};