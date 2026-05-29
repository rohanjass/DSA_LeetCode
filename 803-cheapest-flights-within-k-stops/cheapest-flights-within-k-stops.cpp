class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minh;
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        //minh [ cost , node , stops ]
        //dist [ node , stops ]
        minh.push({0,src,-1}); 
        dist[src][0]=0;
        while(!minh.empty()){
            auto cur=minh.top();
            minh.pop();
            int cost=cur[0];
            int node=cur[1];
            int stops=cur[2];
            if(node==dst) return cost;

            if(stops==k || dist[node][stops+1]<cost) continue;

            for(auto& [nNode,nCost]:adj[node]){
                int nextStop=stops+1;
                if(dist[nNode][nextStop+1]>nCost+cost){
                    dist[nNode][nextStop+1]=nCost+cost;
                    minh.push({(nCost+cost),nNode,nextStop});
                }
            }
        }
    return -1;
    }
};