class Solution {
public:
    void dfs(vector<int>& nums,vector<int>& path,vector<vector<int>>& res,vector<int>& frq){
        if(path.size()==nums.size()){
            res.push_back(path);
        return;
        }
        for(int i=0;i<nums.size();i++){
            if(frq[i]==0){
                path.push_back(nums[i]);
                frq[i]=1;
                dfs(nums,path,res,frq);
                frq[i]=0;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>> res;
        vector<int>frq(nums.size(),0);
        for(int i=0;i<nums.size();i++) frq[i]=0;
        dfs(nums,path,res,frq);
    return res;
    }
};