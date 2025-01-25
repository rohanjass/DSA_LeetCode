class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>> dist(n,vector<int>(k+5,1e9));
        for(auto& flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        priority_queue<tuple<int,int,int>, 
                       vector<tuple<int,int,int>>, 
                       greater<tuple<int,int,int>>> minHeap;
        minHeap.push({0,src,-1});
        dist[src][0]=0;
        while(!minHeap.empty()){
            auto [cost,flight,stops]=minHeap.top();
            minHeap.pop();
            if(flight==dst) return cost;
            if(stops==k || dist[flight][stops+1]<cost) continue;
            for(const auto&[nei,nxtCst]:adj[flight]){
                int nextStops=stops+1;
                if(dist[nei][nextStops+1]>cost+nxtCst){
                    dist[nei][nextStops+1]=cost+nxtCst;
                    minHeap.push({cost+nxtCst,nei,stops+1});
                }
            }
        }
    return -1;
    }
};