class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
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

            for(auto& n:adj[node]){
                int newNode=n.first;
                int newTime=n.second;

                if(!visited.count(newNode)){
                    minH.push({time+newTime,newNode});
                }
            }
        }
    return (visited.size()==n)? t:-1;
    }
};