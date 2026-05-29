class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minh;
        set<pair<int,int>> visited;
        minh.push({grid[0][0],0,0});
        visited.insert({0,0});
        while(!minh.empty()){
            auto cur=minh.top();
            minh.pop();
            int node=cur[0];
            int r=cur[1];
            int c=cur[2];

            if(r==n-1 && c==n-1) return node;
            for(auto& d:dir){
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr<0 || nc<0 || nr==n || nc==n) continue;
                if(!visited.count({nr,nc})){
                    visited.insert({nr,nc});
                    minh.push({max(grid[nr][nc],node),nr,nc});
                }
            }
        }
    return -1;
    }
};