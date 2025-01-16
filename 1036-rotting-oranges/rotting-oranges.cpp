class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        int time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        vector<pair<int, int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(fresh && !q.empty()){
            int length=q.size();
            for(int i=0;i<length;i++){
                auto node=q.front();
                q.pop();
                int r=node.first;
                int c=node.second;
                for(const auto& d:dir){
                    int nr=r+d.first;
                    int nc=c+d.second;
                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }


            }
            time++;
        }
    return fresh==0? time:-1;
    }
};