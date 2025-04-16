class Solution {
public:
    void dfs(int i,int k,int n,vector<int>& path,vector<vector<int>>& res){
        if(k==0 && n==0){
            res.push_back(path);
        return;
        }
        if(i>9 || k<0 || n<0){
            return ;
        } 
        path.push_back(i);
        dfs(i+1,k-1,n-i,path,res);
        path.pop_back();
        dfs(i+1,k,n,path,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int> path;
        dfs(1,k,n,path,res);
    return res;
    }
}; 