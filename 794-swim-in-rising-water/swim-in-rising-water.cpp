class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minH;
        set<pair<int,int>> visited;
        minH.push({grid[0][0],0,0});
        visited.insert({0,0});

        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();

            int node=curr[0];
            int row=curr[1];
            int col=curr[2];

            if(row==n-1 && col==n-1) return node;

            for(auto& d:dir){
                int nr=row+d.first;
                int nc=col+d.second;

                if(nr<0 || nc<0 || nr>=n || nc>=n || visited.count({nr,nc})) continue;

                minH.push({max(node,grid[nr][nc]),nr,nc});
                visited.insert({nr,nc});
            }
        }
    return -1;
    }
};