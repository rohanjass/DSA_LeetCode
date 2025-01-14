class Solution {
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int bfs(vector<vector<int>>& grid,int row,int col){
        queue<pair<int,int>>q;
        grid[row][col]=0;
        q.push({row,col});
        int res=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int curr_row=node.first;
            int curr_col=node.second;
            for(int i=0;i<4;i++){
                int nr=curr_row+dir[i][0];
                int nc=curr_col+dir[i][1];
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=0;
                    res++;
                }
            }
        }
    return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    area=max(area,bfs(grid,i,j));
                }
            }
        }
    return area;
    }
};