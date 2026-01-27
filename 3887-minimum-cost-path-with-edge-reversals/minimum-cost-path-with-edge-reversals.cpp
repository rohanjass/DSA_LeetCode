class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto E:edges){
            adj[E[0]].push_back({E[1],E[2]});
            adj[E[1]].push_back({E[0],2*E[2]});
        }
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minH;
        vector<bool> vis(n,false);
        minH.push({0,0});
        dist[0]=0;
        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();
            int cost=curr.first;
            int node=curr.second;

            if(vis[node]) continue;
            vis[node]=true;

            for(auto [newNode,newCost]:adj[node]){
                if(dist[newNode]>cost+newCost){
                    dist[newNode]=cost+newCost;
                    minH.push({cost+newCost,newNode});
                }
            }
        }
    if(dist[n-1]==1e9) return -1;
    return dist[n-1];
    }
};