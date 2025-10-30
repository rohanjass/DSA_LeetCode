class Solution {
public:
    void def(int i ,int n,int k,vector<int>& path ,vector<vector<int>>& res){
        if(path.size()==k){
            res.push_back(path);
        return;
        }
        if(i>n) return;
        path.push_back(i);
        def(i+1,n,k,path,res);
        path.pop_back();
        def(i+1,n,k,path,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        def(1,n,k,path,res);
    return res;
    }
};