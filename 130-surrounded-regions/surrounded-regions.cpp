class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        if(i<0 ||j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O') return;
        board[i][j]='T';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][c-1]=='O') dfs(i,c-1,board);
        }
        for(int i=0;i<c;i++){
            if(board[0][i]=='O') dfs(0,i,board);
            if(board[r-1][i]=='O') dfs(r-1,i,board);
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='T') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};