class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n,vector<int>(k+5,1e6));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > minH;
        for(auto& f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        } 
        minH.push({0,{src,-1}});
        dist[src][0]=0;
        while(!minH.empty()){
            auto node=minH.top();
            minH.pop();
            int cost=node.first;
            int flight=node.second.first;
            int stops=node.second.second;
            if(flight==dst) return cost;
            if(stops==k || dist[flight][stops+1]<cost) continue;

            for(auto& [nei,nextCost]:adj[flight]){
                int nextStop=stops+1;
                if(dist[nei][nextStop+1]>cost+nextCost){
                    dist[nei][nextStop+1]=cost+nextCost;
                    minH.push({cost+nextCost,{nei,nextStop}});
                }
            }
        }
    return -1;
    }
};