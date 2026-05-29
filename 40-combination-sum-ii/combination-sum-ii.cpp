class Solution {
public:
    int n;
    void findUniqueComb(int ind,vector<int>& nums, int target,vector<int>& path,vector<vector<int>>& res){
        
        if(target==0){
            res.push_back(path);
        return;
        }

        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(target<nums[i]) break;
            path.push_back(nums[i]);
            findUniqueComb(i+1,nums,target-nums[i],path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        findUniqueComb(0,candidates,target,path,res);
    return res;
    }
};