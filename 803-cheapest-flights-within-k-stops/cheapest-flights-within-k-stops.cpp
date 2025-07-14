class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>>dist(n,vector<int>(k+5,1e9));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minH;
        for(auto& f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        minH.push({0,src,-1});//{cost,flight,stopCount}
        dist[src][0]=0;
        while(!minH.empty()){
            auto [cost,flight,stops]=minH.top();
            minH.pop();
            if(flight==dst) return cost;
            if(stops==k || dist[flight][stops+1]<cost) continue;
            for(auto& [neig,nextCost]:adj[flight]){
                int nextStop=stops+1;
                if(dist[neig][nextStop+1]>cost+nextCost){
                    dist[neig][nextStop+1]=cost+nextCost;
                    minH.push({cost+nextCost,neig,nextStop});
                }
            }
        }
    return -1;
    }
};