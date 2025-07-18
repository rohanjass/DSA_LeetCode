class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>> visited;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>minH;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        minH.push({grid[0][0],0,0});
        visited.insert({0,0});
        while(!minH.empty()){
            auto curr=minH.top();
            minH.pop();
            int time=curr[0];
            int r=curr[1];
            int c=curr[2];
            if(r==n-1 && c==n-1) return time;
            for(const auto& d:dir){
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr<0 || nc<0 || nr>=n || nc>=n || visited.count({nr,nc})) continue;
                visited.insert({nr,nc});
                minH.push({max(time,grid[nr][nc]),nr,nc});
            }
        }
    return -1;
    }
};