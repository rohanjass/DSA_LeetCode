class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        const long long INF = 1e18;

        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<original.size();i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v,cost[i]});
        }
        vector<vector<long long>> dist(26,vector<long long>(26,INF));

        for(int s=0;s<26;s++){
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> minH;
            dist[s][s]=0;
            minH.push({0,s});

            while(!minH.empty()){
                auto [d,u]=minH.top();
                minH.pop();

                if(d>dist[s][u]) continue;

                for(auto& [v,w]:adj[u]){
                    if(dist[s][v]>d+w){
                        dist[s][v]=d+w;
                        minH.push({dist[s][v],v});
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<target.size();i++){
            int s=source[i]-'a';
            int t=target[i]-'a';

            if(dist[s][t]==INF) return -1;
            ans+=dist[s][t];
        }
    return ans;   
    }
};