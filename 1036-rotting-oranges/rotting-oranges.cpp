class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0,time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty() && fresh){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto cur=q.front();
                q.pop();
                int row=cur.first;
                int col=cur.second;

                for(auto& d:dir){
                    int nr=row+d.first;
                    int nc=col+d.second;
                    if(nc>=0 && nr>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return (fresh==0)? time:-1;
    }
};