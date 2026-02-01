class Solution {
public:
    void def(int node,int ind,vector<int>& vis,unordered_map<int,vector<int>>& adj,vector<vector<int>>& res){
        for(int n:adj[node]){
            if(vis[n]==0){
                vis[n]=1;
                res[ind].push_back(n);
                def(n,ind,vis,adj,res);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            vector<int>vis (n,0);
            def(i,i,vis,adj,res);
            sort(res[i].begin(),res[i].end());
        }
    return res;
    }
};