class Solution {
public:
    int startRow=-1,startCol=-1;
    int endRow=-1,endCol=-1;
    int total=0;
    int m=0,n=0;

    int func(int i,int j,int c,vector<vector<int>>& grid){
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]==-1) return 0;
        if(grid[i][j]==2 ){
            if(c==total) return 1;
        return 0;
        }
        int temp=grid[i][j];
        grid[i][j]=-1;
        int path=0;
        path+=func(i,j-1,c+1,grid);
        path+=func(i,j+1,c+1,grid);
        path+=func(i-1,j,c+1,grid);
        path+=func(i+1,j,c+1,grid);
        grid[i][j]=temp;
    return path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    startRow=i;
                    startCol=j;
                } 
                if(grid[i][j]!=-1){
                    total++;
                }
            }
        }
    return func(startRow,startCol,1,grid);

    }
};