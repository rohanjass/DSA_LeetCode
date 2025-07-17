class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int s=times.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        for(const auto& t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
        minH.push({0,k});
        set<int> visited;
        int t=0;
        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();
            int t1=curr.first;
            int n1=curr.second;
            if(visited.count(n1)) continue;
            visited.insert(n1);
            t=t1;
            for(const auto& nei:adj[n1]){
                int n2=nei.first;
                int t2=nei.second;
                if(!visited.count(n2)){
                    minH.push({t1+t2,n2});
                }
            }
        }
    return (visited.size()==n)? t:-1;
    }
};