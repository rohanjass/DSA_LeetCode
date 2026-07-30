class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minH;
        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        unordered_set<int> visited;

        minH.push({0,k});
        int t=0;

        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();
            int time=curr.first;
            int node=curr.second;

            if(visited.count(node)) continue;
            visited.insert(node);
            t=time;
            for(auto& nei:adj[node]){
                int newNode=nei.first;
                int newTime=nei.second;
                if(!visited.count(newNode)){
                    minH.push({time+newTime,newNode});
                }
            }
        }
    return (visited.size()==n)? t:-1;
    }
};