class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minH;
        unordered_set<int> visited;
        minH.push({0,k});
        int t=0;
        while(!minH.empty()){
            auto cur=minH.top();
            minH.pop();
            int time=cur.first;
            int node=cur.second;

            if(visited.count(node)) continue;
            visited.insert(node);
            t=time;
            for(auto& N:adj[node]){
                int newTime=N.second;
                int newNode=N.first;
                if(!visited.count(newNode)){
                    minH.push({time+newTime,newNode});
                }
            }
            
        }
    return (visited.size()==n)? t:-1;
    }
};