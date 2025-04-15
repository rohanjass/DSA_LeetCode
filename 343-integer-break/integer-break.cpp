class Solution {
public:
    void dfs(int n,int sum,int start,vector<int>& path,vector<vector<int>>& res){
        if(sum==n){
          if(path.size()>=2) res.push_back(path);
          return;
        }
        if(sum>n) return;
        for(int i=start;i<n;i++){
            path.push_back(i);
            dfs(n,sum+i,i,path,res);
            path.pop_back();
        }
    }
    int integerBreak(int n) {
        vector<vector<int>> res;
        vector<int> path;
        int result=1;
        dfs(n,0,1,path,res);
        for(auto& vec:res){
            int prod=1;
            for(int num:vec) prod*=num;
        result=max(result,prod);
        }
    return result;
    }
};