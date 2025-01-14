class Solution {
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void bfs(vector<vector<char>>& grid,int row,int col){
        queue<pair<int,int>>q;
        grid[row][col]='0';
        q.push({row,col});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int curr_row = node.first;  // Was using 'row' instead of current position
            int curr_col = node.second;
            
            // Check all 8 directions
            for(int i=0;i<4;i++){
                int nr=curr_row+dir[i][0];
                int nc=curr_col+dir[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                        q.push({nr, nc});
                        grid[nr][nc] = '0';  // Mark as visited
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    island++;
                }
            }
        }
    return island;
    }
};