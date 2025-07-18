class Solution {
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
public:
    int bfs(int i,int j,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        grid[i][j]=0;
        q.push({i,j});
        int res=1;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int r=top.first;
            int c=top.second;
            for(auto d:dir){
                int nr=r+d.first;
                int nc=c+d.second;
                if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || grid[nr][nc]!=1) continue;
                q.push({nr,nc});
                grid[nr][nc]=0;
                res++;
            }
        }
    return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) maxArea=max(maxArea,bfs(i,j,grid));
            }
        }
    return maxArea;
    }
};