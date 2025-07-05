class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int r,int c,int ind){
        if(ind==word.size()) return true;
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[ind] || board[r][c]=='!') return false;
        char ch=board[r][c];
        board[r][c]='!';
        bool l=dfs(board,word,r+1,c,ind+1);
        bool ri=dfs(board,word,r,c+1,ind+1);
        bool u=dfs(board,word,r-1,c,ind+1);
        bool d=dfs(board,word,r,c-1,ind+1);
        board[r][c]=ch;

        return l||ri||u||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
    return false;
    }
};