class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > minH;
        vector<vector<int>> dist(n,vector<int>(k+5,1e6));

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
            if(stops==k || dist[flight][stops+1]>cost) continue;

            for(auto& [newNode,newCost]:adj[flight]){
                int newStops=stops+1;
                if(dist[newNode][newStops+1]>newCost+cost){
                    dist[newNode][newStops+1]=newCost+cost;
                    minH.push({dist[newNode][newStops+1],{newNode,newStops}});
                }
            }
        }

    return -1;
    }
};