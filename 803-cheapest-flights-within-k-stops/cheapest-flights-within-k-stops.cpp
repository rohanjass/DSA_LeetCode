class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minH;
        vector<vector<int>> dist(n,vector<int>(k+2,1e9));

        for(auto& f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        minH.push({0,src,-1});
        dist[src][0]=0;

        while(!minH.empty()){
            auto cur=minH.top();
            minH.pop();

            int cost=cur[0];
            int node=cur[1];
            int stops=cur[2];

            if(node==dst) return cost;

            if(stops==k || cost>dist[node][stops+1]) continue;

            for(auto& [nNode,nCost]:adj[node]){
                int nextStop=stops+1;

                if(dist[nNode][nextStop+1]>nCost+cost){
                    dist[nNode][nextStop+1]=nCost+cost;
                    minH.push({nCost+cost,nNode,nextStop});
                }
            }
        }
    return -1;
    }
};