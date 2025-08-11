class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<pair<int,int>>>adj;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> minH;
        int n=points.size();
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

        minH.push({0,0});
        int res=0;
        while(visited.size()<n){
            auto curr=minH.top();
            minH.pop();
            int dist=curr.first;
            int node=curr.second;
            if(visited.count(node))continue;
            res+=dist;
            visited.insert(node);
            for(const auto& i:adj[node]){
                int nDist=i.first;
                int nNode=i.second;
                if(!visited.count(nNode)){
                    minH.push({nDist,nNode});
                }
            }
        }
    return res;
    }
};