class Solution {
    public int numEnclaves(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int[][] dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,dir);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid,dir);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,dir);
            }
            if(grid[n-1][i]==1){
                dfs(n-1,i,grid,dir);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1) count++;
            }
        }
    return count;
    }
    private void dfs(int r,int c,int[][] grid,int[][] dir){
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(nr>=0 && nc>=0 && nr<grid.length && nc<grid[0].length && grid[nr][nc]==1){
                dfs(nr,nc,grid,dir);
            }
        }
    }
}