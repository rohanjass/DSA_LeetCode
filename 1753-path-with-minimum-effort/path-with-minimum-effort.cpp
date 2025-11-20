class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minH;
        set<pair<int,int>> visited;
        minH.push({0,0,0});

        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();
            int node=curr[0];
            int r=curr[1];
            int c=curr[2];

            if(r==m-1 && c==n-1) return node;
            if(visited.count({r,c})) continue;
            visited.insert({r,c});
            for(auto& d:dir){
                int nr=r+d.first;
                int nc=c+d.second;

                if(nr<0 || nc<0 || nr>=m || nc>=n || visited.count({nr,nc})) continue;
                int diff=abs(heights[r][c]-heights[nr][nc]);
                minH.push({max(node,diff),nr,nc});
            }
        }
    return -1;
    }
};