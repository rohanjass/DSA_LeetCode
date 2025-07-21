class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j}); 
            }
        }
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        while(!q.empty() && fresh){
            int len=q.size();
            for(int i=0;i<len;i++){
                auto curr= q.front();
                q.pop();
                int r=curr.first;
                int c=curr.second;
                for(const auto& d:dir){
                    int nr=r+d.first;
                    int nc=c+d.second;
                    if(nr<0 || nc<0 || nr>=grid.size() || nc >=grid[0].size() || grid[nr][nc]==0 || grid[nr][nc]==2) continue;
                    fresh--;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
            time++;
        }
    return (fresh==0)? time:-1;
    }
};