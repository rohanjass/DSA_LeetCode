class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=abs(x2-x1)+abs(y2-y1);
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }
        int res=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> minH;
        unordered_set<int>visited;
        minH.push({0,0});
        while(visited.size()<n){
            auto curr=minH.top();
            minH.pop();
            int cost=curr.first;
            int node=curr.second;
            if(visited.count(node)) continue;
            res+=cost;
            visited.insert(node);
            for(const auto& nei:adj[node]){
                int neiCost=nei.first;
                int neiNode=nei.second;
                if(!visited.count(neiNode)){
                    minH.push({neiCost,neiNode});
                }
            }
        }
    return res;
    }
};