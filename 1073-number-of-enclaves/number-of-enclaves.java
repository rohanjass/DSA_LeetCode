class Solution {
    
    public int numEnclaves(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int[][] dir = {{-1,0},{0,-1},{0,1},{1,0}};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,dir,i,0);
            }
            if(grid[i][m-1]==1){
                dfs(grid,dir,i,m-1);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(grid,dir,0,j);
            }
            if(grid[n-1][j]==1){
                dfs(grid,dir,n-1,j);
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
    private void dfs(int[][] grid,int[][] dir,int r,int c){
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(nr>=0 && nc>=0 && nr<grid.length && nc<grid[0].length && grid[nr][nc]==1){
                dfs(grid,dir,nr,nc);
            }
        }
    }
}