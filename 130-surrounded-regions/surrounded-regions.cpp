class Solution {
public:
    void capture(vector<vector<char>>& board,int r,int c){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!='O') return;
        board[r][c]='T';
        capture(board,r+1,c);
        capture(board,r-1,c);
        capture(board,r,c+1);
        capture(board,r,c-1);
    }

    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int r=0;r<row;r++){
            if(board[r][0]=='O') capture(board,r,0);
            if(board[r][col-1]=='O') capture(board,r,col-1);
        }
        for(int c=0;c<col;c++){
            if(board[0][c]=='O') capture(board,0,c);
            if(board[row-1][c]=='O') capture(board,row-1,c);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='T') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};