class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> minH;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        ways[0]=1;
        minH.push({0,0});//time=0,src=0
        dist[0]=0;
        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();

            int node=curr.second;
            long long time=curr.first;
            
            if(time> dist[node]) continue;
            for(auto& next:adj[node]){
                int nextNode=next.first;
                long long nextTime=next.second;
                if(dist[nextNode]>time+nextTime){
                    dist[nextNode]=time+nextTime;
                    ways[nextNode]=ways[node];
                    minH.push({nextTime+time,nextNode});
                } else if(dist[nextNode]==time+nextTime){
                    ways[nextNode]=(ways[nextNode]+ways[node])%MOD;
                }
            }
        }
    return ways[n-1];
    }
};