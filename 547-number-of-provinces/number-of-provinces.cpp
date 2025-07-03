class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> vis(isConnected.size());
        int curr=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                curr++;
            }
        }
        return curr;
    }

    void dfs(vector<vector<int>>& isConnected,vector<bool>& vis,int node){
        vis[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !vis[i]){
                dfs(isConnected,vis,i);
            }
        }
    }
};