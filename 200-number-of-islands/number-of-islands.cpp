class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void def(int r,int c ,vector<vector<char>>& arr){
        arr[r][c]='0';
        for(auto d:dir){
            int nr=r+d.first;
            int nc=c+d.second;
            if(nr<0 || nc<0 || nr>= arr.size() || nc>=arr[0].size() || arr[nr][nc]=='0') continue;
            def(nr,nc,arr);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int island=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    island++;
                    def(i,j,grid);
                }
            }
        }
    return island;
    }
};